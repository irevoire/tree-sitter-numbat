const PREC = {
  number: 19,
  factor: 8,
  primary: 0,
}


module.exports = grammar({
  name: 'numbat',

  extras: $ => [token(" "), $.line_comment],

  externals: $ => [
    $._string_content,
    $._float,
  ],

  // word: $ => $.identifier,

  rules: {
    source_file: $ => seq(
      optional(seq($.shebang, /\n/)),
      repeat(seq(optional($._statement), /\r?\n/)),
    ),

    shebang: _ => /#!.*/,

    //! statement       →   variable_decl | function_decl | dimension_decl | decorator | unit_decl | module_import | procedure_call | expression
    _statement: $ => choice(
      $._expression
    ),

    // ============ EXPRESSION
    
    //! expression      →   postfix_apply
    _expression: $ => choice(
      $.factor,
      $._primary,
    ),

    //! factor          →   negate ( ( "*" | "/") per_factor ) *
    factor: $ => prec.left(PREC.factor, seq(
      field("left", $._expression),
      field("op", choice($.multiply, $.divide)),
      field("right", $._expression),
    )),

    //! primary         →   string | boolean | hex_number | oct_number | bin_number | number | identifier | "(" expression ")"
    _primary: $ => prec(PREC.primary, choice(
      $.number,
    )),

    number: $ => prec(PREC.number, choice(
      $._float,
    )),

    //! multiply        →   "*" | "·" | "×"
    multiply: $ => choice("*", "·", "×"),

    //! divide          →   "/" | "÷"
    divide: $ => choice("/", "÷"),   

    line_comment: _ => token(seq(
      '#', /.*/,
    )),

  }
});
