
const PREC = {
  dim_primary: 17,  
  dim_exponent: 16,
  dim_power: 15,
  dim_factor: 14,  

  postfix_apply: 13,
  condition: 12,
  conversion: 11,
  comparison: 10,
  term: 9,
  factor: 8,
  per_factor: 7,
  negate: 6,
  ifactor: 5,
  power: 4,
  factorial: 3,
  unicode_power: 2,
  call: 1,
  primary: 0,
}


module.exports = grammar({
  name: 'numbat',
  extras: $ => [/\s/, $.line_comment],

  conflicts: $ => [
    [$._call],
    [$._term]
  ],

  word: $ => $.identifier,

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
    _dimension_expr: $ => choice(
      $._dim_factor,
      $._dim_power,
      $._dim_exponent,
      $._dim_primary
    ),

    //! dim_factor      →   dim_power ( (multiply | divide) dim_power ) *
    _dim_factor: $ => prec.left(PREC.dim_factor, seq(
      $._dimension_expr,
      choice($.multiply, $.divide),
      $._dimension_expr,
    )),

    //! dim_power       →   dim_primary ( power dim_exponent | unicode_exponent ) ?
    _dim_power: $ => prec(PREC.dim_power, seq(
      $._dimension_expr,
      choice(
        seq($._power, $._dim_exponent),
        $.unicode_exponent,
      ),
    )),

    //! dim_exponent    →   number | minus dim_exponent | "(" dim_exponent ( divide dim_exponent ) ? ")"
    _dim_exponent: $ => prec(PREC.dim_exponent, choice(
      $.number,
      seq($.minus, $._dim_exponent),
      seq("(", $._dim_exponent, optional(seq($.divide, $._dim_exponent)), ")"),
    )),

    //! dim_primary     →   identifier | number | ( "(" dimension_expr ")"
    _dim_primary: $ => prec(PREC.dim_primary, choice(
      $.identifier,
      $.number,
      seq("(", $._dimension_expr, ")"),
    )),

    // ============ EXPRESSION
    
    //! expression      →   postfix_apply
    _expression: $ => choice(
      $._postfix_apply,
      $._condition,
      $._conversion,
      $._comparison,
      $._term,
      $._factor,
      $._per_factor,
      $._negate,
      // $._ifactor,
      $._power,
      $._factorial,
      $._unicode_power,
      $._call,
      $._primary,
    ),

    //! postfix_apply   →   condition ( "//" identifier ) *
    _postfix_apply: $ => prec.left(PREC.postfix_apply, seq(
      $._expression,
      repeat(seq("//", $.identifier))
    )),

    //! condition       →   "if" conversion "then" condition "else" condition | conversion
    _condition: $ => prec.left(PREC.condition, choice(
      seq("if", $._expression, "then", $._expression, "else", $._expression),
      $._expression
    )),

    //! conversion      →   comparison ( ( "→" | "->" | "to" ) comparison ) *
    _conversion: $ => prec.left(PREC.conversion, seq(
      $._expression,
      choice("→", "->", "to"),
      $._expression
    )),

    //! comparison      →   term ( (">" | ">="| "≥" | "<" | "<=" | "≤" | "==" | "!=" | "≠" ) term ) *
    _comparison: $ => prec.left(PREC.comparison, seq(
      $._expression,
      choice(">", ">=", "≥", "<=", "≤", "<", "==", "!=", "≠"),
      $._expression,
    )),

    //! term            →   factor ( ( "+" | "-") factor ) *
    _term: $ => prec.left(PREC.term, seq(
      $._expression,
      choice($.plus, $.minus),
      $._expression,
    )),

    //! factor          →   negate ( ( "*" | "/") per_factor ) *
    _factor: $ => prec.left(PREC.factor, seq(
      $._expression,
      choice($.multiply, $.divide),
      $._expression,
    )),

    //! per_factor      →   negate ( "per" negate ) *
    _per_factor: $ => prec.left(PREC.per_factor, seq(
      $._expression,
      "per",
      $._expression,
    )),

    //! negate          →   ( "-" negate ) | ifactor
    _negate: $ => prec(PREC.negate, seq("-", $._expression)),

    //! ifactor         →   power ( " " power ) *
    _ifactor: $ => prec.left(PREC.ifactor, seq(
      $._expression,
      " ",
      $._expression,
    )),

    //! power           →   factorial ( "^" "-" ? power ) ?
    _power: $ => prec.left(PREC.power, seq(
      $._expression,
      $.pow_symbol,
      optional($.minus),
      $._expression,
    )),

    //! factorial       →   unicode_power "!" *
    _factorial: $ => prec(PREC.factorial, seq($._expression, "!")),
    
    //! unicode_power   →   call ( "⁻" ? ("¹" | "²" | "³" | "⁴" | "⁵" ) ) ?
    _unicode_power: $ => prec(PREC.unicode_power, seq(
      $._expression,
      optional("⁻"),
      choice("¹", "²", "³", "⁴", "⁵")
    )),

    //! call            →   primary ( "(" arguments? ")" ) ?
    _call: $ => prec(PREC.call, seq(
      $._expression,
      "(",
      optional($._arguments),
      ")"
    )),

    //! arguments       →   expression ( "," expression ) *
    _arguments: $ => seq(
      $._expression,
      ",",
      $._expression
    ),

    //! primary         →   number | hex-number | oct-number | bin-number | identifier | "(" expression ")"
    _primary: $ => prec(PREC.primary, choice(
      $.number,
      // $.hex_number,
      // $.oct_number,
      // $.bin_number,
      $.identifier,
      seq("(", $._expression, ")")
    )),

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
