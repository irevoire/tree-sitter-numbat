const PREC = {
  string: 23,
  hex_number: 22,
  oct_number: 21,
  bin_number: 20,
  number: 19,
  identifier: 18,

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
    [$._ifactor]
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
      $.dimension_decl,
      $.decorator,
      $.unit_decl,
      $.module_import,
      $.procedure_call,
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

    // ============ DIMENSION DECLARATION
    //! dimension_decl  →   "dimension" identifier ( "=" dimension_expr ) *
    dimension_decl: $ => seq(
      "dimension",
      $.identifier,
      repeat(seq(
        "=",
        $._dimension_expr
      ))
    ),


    // ============ DECORATOR
    //! decorator       →   "@" ( "metric_prefixes" | "binary_prefixes" | ( "aliases(" list_of_alsiases ")" ) )
    decorator: $ => seq(
      "@",
      choice(
        "metric_prefixes",
        "binary_prefixes",
        seq("aliases(", $._list_of_aliases, ")")
      ),
    ),

    //! list_of_aliases →   "@" ( "metric_prefixes" | "binary_prefixes" | ( "aliases(" list_of_alsiases ")" ) )
    _list_of_aliases: $ => seq(
      repeat(seq(
        $.identifier,
        optional(seq(":", choice("long", "short", "both", "none"))),
        ","
      )),
      seq(
        $.identifier,
        optional(seq(":", choice("long", "short", "both", "none"))),
      )
    ),

    
    // ============ UNIT DECLARATION
    //! unit_decl       →   "unit" ( ":" dimension_expr ) ? ( "=" expression ) ?
    unit_decl: $ => seq(
      "unit",
      optional(seq(
        ":", $._dimension_expr
      )),
      optional(seq(
        "=", $._expression
      ))
    ),

    //! module_import   →   "use" ident ( "::" ident) *
    module_import: $ => seq(
      "use",
      $.identifier,
      repeat(seq(
        "::", $.identifier
      )),
    ),

    //! procedure_call   →   ( "print" | "assert_eq" | "type" ) "(" arguments ")"
    procedure_call: $ => seq(
      choice("print", "assert_eq", "type"),
      "(",
      $._arguments,
      ")",
    ),

    //! type_annotation →   boolean | string | dimension_expr
    _type_annotation: $ => choice(
      $.boolean,
      $.string,
      $._dimension_expr
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
        seq($.power, $._dim_exponent),
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
      $.postfix_apply,
      $.condition,
      $.conversion,
      $.comparison,
      $.term,
      $.factor,
      $.per_factor,
      $.negate,
      // $._ifactor,
      $.power,
      $.factorial,
      $.unicode_power,
      $.call,
      $._primary,
    ),

    //! postfix_apply   →   condition ( "//" identifier ) *
    postfix_apply: $ => prec.right(PREC.postfix_apply, seq(
      $._expression,
      "//",
      $.identifier
    )),

    //! condition       →   "if" conversion "then" condition "else" condition | conversion
    condition: $ => prec.left(PREC.condition, seq(
      "if",
      $._expression,
      "then",
      $._expression,
      "else",
      $._expression
    )),

    //! conversion      →   comparison ( ( "→" | "->" | "to" ) comparison ) *
    conversion: $ => prec.left(PREC.conversion, seq(
      field("left", $._expression),
      field("op", choice("→", "->", "to")),
      field("right", $._expression)
    )),

    //! comparison      →   term ( (">" | ">="| "≥" | "<" | "<=" | "≤" | "==" | "!=" | "≠" ) term ) *
    comparison: $ => prec.left(PREC.comparison, seq(
      field("left", $._expression),
      field("op", choice(">", ">=", "≥", "<=", "≤", "<", "==", "!=", "≠")),
      field("right", $._expression),
    )),

    //! term            →   factor ( ( "+" | "-") factor ) *
    term: $ => prec.left(PREC.term, seq(
      field("left", $._expression),
      field("op", choice($.plus, $.minus)),
      field("right", $._expression),
    )),

    //! factor          →   negate ( ( "*" | "/") per_factor ) *
    factor: $ => prec.left(PREC.factor, seq(
      field("left", $._expression),
      field("op", choice($.multiply, $.divide)),
      field("right", $._expression),
    )),

    //! per_factor      →   negate ( "per" negate ) *
    per_factor: $ => prec.left(PREC.per_factor, seq(
      field("left", $._expression),
      field("op", "per"),
      field("right", $._expression),
    )),

    //! negate          →   ( "-" negate ) | ifactor
    negate: $ => prec(PREC.negate, seq("-", $._expression)),

    //! ifactor         →   power ( " " power ) *
    _ifactor: $ => prec.left(PREC.ifactor, seq(
      field("left", $._expression),
      // space are automatically inserted
      field("right", $._primary),
    )),

    //! power           →   factorial ( "^" "-" ? power ) ?
    power: $ => prec.left(PREC.power, seq(
      field("left", $._expression),
      $.pow_symbol,
      field("power", seq(
        optional($.minus),
        $._expression
      ))
    )),

    //! factorial       →   unicode_power "!" *
    factorial: $ => prec(PREC.factorial, seq($._expression, "!")),
    
    //! unicode_power   →   call ( "⁻" ? ("¹" | "²" | "³" | "⁴" | "⁵" ) ) ?
    unicode_power: $ => prec(PREC.unicode_power, seq(
      $._expression,
      optional("⁻"),
      choice("¹", "²", "³", "⁴", "⁵")
    )),

    //! call            →   primary ( "(" arguments? ")" ) ?
    call: $ => prec(PREC.call, seq(
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

    //! primary         →   string | boolean | hex_number | oct_number | bin_number | number | identifier | "(" expression ")"
    _primary: $ => prec(PREC.primary, choice(
      $.string,
      $.boolean,
      $.hex_number,
      $.oct_number,
      $.bin_number,
      $.number,
      $.identifier,
      seq("(", $._expression, ")")
    )),

    // TODO: handle escaped strings
    //! string          →   /"[^"]*"/
    string: $ => prec(PREC.string, seq(
      /"[^"]*"/
    )),

    //! boolean         →   true | false
    boolean: $ => choice(
      "true",
      "false"
    ),

    //! number          →   /[0-9][0-9_]*(\.([0-9][0-9_]*)?)?([eE][+-]?[0-9][0-9_]*)?/
    number: $ => prec(PREC.number, seq(
      /[0-9][0-9_]*(\.([0-9][0-9_]*)?)?([eE][+-]?[0-9][0-9_]*)?/
    )),

    //! hex_number      →   /0x[0-9a-fA-F]*/
    hex_number: $ => prec(PREC.hex_number, seq(
      /0x[0-9a-fA-F]*/
    )),

    //! oct_number      →   /0o[0-7]*/
    oct_number: $ => prec(PREC.hex_number, seq(
      /0o[0-7]*/
    )),

    //! bin_number      →   /0b[01]*/
    bin_number: $ => prec(PREC.hex_number, seq(
      /0b[01]*/
    )),

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
