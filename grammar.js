module.exports = grammar({
  name: 'numbat',
  extras: $ => [/\s/, $.line_comment],

  conflicts: $ => [
    [$._call],
    [$._term],
  ],

  rules: {
    source_file: $ => seq(
      optional($.shebang),
      repeat($._statement),
    ),

    shebang: _ => /#!.*/,

    //! statement       →   variable_decl | function_decl | dimension_decl | decorator | unit_decl | module_import | procedure_call | expression
    _statement: $ => choice(
      $.variable_decl,
      $.function_decl,
      // $.dimension_decl,
      // $.decorator,
      // $.unit_decl,
      // $.module_import,
      // $.procedure_call,
      $._expression
    ),
    
    //! variable_decl   →   "let" identifier ( ":" type_annotation ) ? "=" expression
    variable_decl: $ => seq(
      "let",
      field("name", $.identifier),
      field("type_parameter", optional(seq(":", $._type_annotation))),
      "=",
      field("value", $._expression)
    ),

    // ============ FUNCTION DECLARATION

    //! function_decl   →   "fn" identifier ( fn_decl_generic ) ? fn_decl_param "->" type_annotation "=" expression
    function_decl: $ => seq(
      "fn",
      field("name", $.identifier),
      field("type_parameter", optional($._fn_decl_generic)),
      $._fn_decl_param,
      "->",
      $._type_annotation,
      "=",
      $._expression
    ),

    //! fn_decl_generic →   "<" ( identifier "," ) * identifier ? ">"
    _fn_decl_generic: $ => seq(
      "<",
      repeat(seq($.identifier, ",")),
      optional($.identifier),
      ">",
    ),

    //! fn_decl_param   →   "(" ( identifier ( ":" dimension_expr ) ? "," )* ( identifier ( ":" dimension_expr ) ) ? ")"
    _fn_decl_param: $ => seq(
      "(",
      repeat(seq(
        $.identifier,
        optional(seq(":", $._dimension_expr)),
        ",",
      )),
      optional(seq(
        $.identifier,
        optional(seq(":", $._dimension_expr)),
      )),
      ")",
    ),

    //! type_annotation →   bool | string | dimension_expr
    _type_annotation: $ => choice(
      $.bool,
      $.string,
      $._dimension_expr
    ),

    //! bool            →   true | false
    bool: $ => choice(
      "true",
      "false",
    ),
    
    //! string          →   "\" ... "\""
    string: $ => seq(
      "\"",
      repeat(/[^"]/),
      "\"",
    ),
    
    //! dimension_expr  →   dim_factor
    _dimension_expr: $ => $._dim_factor,

    //! dim_factor      →   dim_power ( (multiply | divide) dim_power ) *
    _dim_factor: $ => seq(
      $._dim_power,
      repeat(seq(choice($.multiply, $.divide), $._dim_power)),
    ),

    //! dim_power       →   dim_primary ( power dim_exponent | unicode_exponent ) ?
    _dim_power: $ => seq(
      $._dim_primary,
      optional(choice(
        seq($._power, $._dim_exponent),
        $.unicode_exponent,
      )),
    ),

    //! dim_exponent    →   number | minus dim_exponent | "(" dim_exponent ( divide dim_exponent ) ? ")"
    _dim_exponent: $ => choice(
      $.number,
      seq($.minus, $._dim_exponent),
      seq("(", $._dim_exponent, optional(seq($.divide, $._dim_exponent)), ")"),
    ),

    //! dim_primary     →   identifier | number | ( "(" dimension_expr ")"
    _dim_primary: $ => choice(
      $.identifier,
      $.number,
      seq("(", $._dimension_expr, ")"),
    ),

    // ============ EXPRESSION
    
    //! expression      →   postfix_apply
    _expression: $ => $._postfix_apply,

    //! postfix_apply   →   condition ( "//" identifier ) *
    _postfix_apply: $ => seq(
      $._condition,
      repeat(seq("//", $.identifier))
    ),

    //! condition       →   "if" conversion "then" condition "else" condition | conversion
    _condition: $ => choice(
      seq("if", $._conversion, "then", $._condition, "else", $._condition),
      $._conversion
    ),

    //! conversion      →   comparison ( ( "→" | "->" | "to" ) comparison ) *
    _conversion: $ => seq(
      $._comparison,
      repeat(
        seq(
          choice("→", "->", "to"),
          $._comparison,
        )
      )
    ),

    //! comparison      →   term ( (">" | ">="| "≥" | "<" | "<=" | "≤" | "==" | "!=" | "≠" ) term ) *
    _comparison: $ => seq(
      $._term,
      repeat(
        seq(
          choice(">", ">=", "≥", "<=", "≤", "<", "==", "!=", "≠"),
          $._term,
        )
      )
    ),

    //! term            →   factor ( ( "+" | "-") factor ) *
    _term: $ => seq(
      $._factor,
      repeat(
        seq(
          choice($.plus, $.minus),
          $._factor,
        )
      )
    ),

    //! factor          →   negate ( ( "*" | "/") per_factor ) *
    _factor: $ => seq(
      $._negate,
      repeat(
        seq(
          choice($.multiply, $.divide),
          $._per_factor,
        )
      )
    ),

    //! per_factor      →   negate ( "per" negate ) *
    _per_factor: $ => seq(
      $._negate,
      repeat(
        seq(
          "per",
          $._negate,
        )
      )
    ),

    //! negate          →   ( "-" negate ) | ifactor
    _negate: $ => choice(
      seq("-", $._negate),
      $._ifactor,
    ),

    //! ifactor         →   power ( " " power ) *
    _ifactor: $ => seq(
      $._power,
      repeat(
        seq(
          " ",
          $._power,
        )
      )
    ),

    //! power           →   factorial ( "^" "-" ? power ) ?
    _power: $ => seq(
      $._factorial,
      optional(
        seq(
          $.pow_symbol,
          optional($.minus),
          $._power,
        )
      )
    ),

    //! factorial       →   unicode_power "!" *
    _factorial: $ => seq($._unicode_power, repeat("!")),
    
    //! unicode_power   →   call ( "⁻" ? ("¹" | "²" | "³" | "⁴" | "⁵" ) ) ?
    _unicode_power: $ => seq(
      $._call,
      optional(seq(optional("⁻"), choice("¹", "²", "³", "⁴", "⁵")))
    ),

    //! call            →   primary ( "(" arguments? ")" ) ?
    _call: $ => seq(
      $._primary,
      optional(seq("(", optional($._arguments), ")"))
    ),

    //! arguments       →   expression ( "," expression ) *
    _arguments: $ => seq(
      $._expression,
      repeat(seq(",", $._expression))
    ),

    //! primary         →   number | hex-number | oct-number | bin-number | identifier | "(" expression ")"
    _primary: $ => choice(
      $.number,
      // $.hex_number,
      // $.oct_number,
      // $.bin_number,
      $.identifier,
      seq("(", $._expression, ")")
    ),

    //! number          →   /[0-9][0-9_]*(\.[0-9][0-9]*)?/
    number: $ => seq(
      /[0-9][0-9_]*(\.[0-9][0-9]*)?/
    ),

    //! identifier      →   [a-zA-Z_][a-zA-Z_0-9]*
    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,

    //! plus            →   "+"
    plus: $ => "+",

    //! minus           →   "-"
    minus: $ => "-",

    //! multiply        →   "*" | "·" | "×"
    multiply: $ => choice("*", "·", "×"),

    //! divide          →   "/" | "÷"
    divide: $ => choice("/", "÷"),

    //! pow_symbol      →   "**" | "^"
    pow_symbol: $ => choice("**", "^"),
    
    //! unicode_exponent→    "¹" | "²" | "³" | "⁴" | "⁵" | "⁶" | "⁷" | "⁸" | "⁹" 
    unicode_exponent: $ => choice( "¹", "²", "³", "⁴", "⁵", "⁶", "⁷", "⁸", "⁹"),
   
    line_comment: _ => token(seq(
      '#', /.*/,
    )),

  }
});
