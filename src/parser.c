#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 22
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 85
#define ALIAS_COUNT 0
#define TOKEN_COUNT 73
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 2

enum {
  sym_identifier = 1,
  aux_sym_source_file_token1 = 2,
  aux_sym_source_file_token2 = 3,
  sym_shebang = 4,
  anon_sym_let = 5,
  anon_sym_COLON = 6,
  anon_sym_EQ = 7,
  anon_sym_fn = 8,
  anon_sym_DASH_GT = 9,
  anon_sym_LT = 10,
  anon_sym_COMMA = 11,
  anon_sym_GT = 12,
  anon_sym_LPAREN = 13,
  anon_sym_RPAREN = 14,
  anon_sym_dimension = 15,
  anon_sym_AT = 16,
  anon_sym_metric_prefixes = 17,
  anon_sym_binary_prefixes = 18,
  anon_sym_aliases_LPAREN = 19,
  anon_sym_long = 20,
  anon_sym_short = 21,
  anon_sym_both = 22,
  anon_sym_none = 23,
  anon_sym_unit = 24,
  anon_sym_use = 25,
  anon_sym_COLON_COLON = 26,
  anon_sym_print = 27,
  anon_sym_assert_eq = 28,
  anon_sym_type = 29,
  anon_sym_SLASH_SLASH = 30,
  anon_sym_if = 31,
  anon_sym_then = 32,
  anon_sym_else = 33,
  anon_sym_ = 34,
  anon_sym_to = 35,
  anon_sym_GT_EQ = 36,
  anon_sym_2 = 37,
  anon_sym_LT_EQ = 38,
  anon_sym_3 = 39,
  anon_sym_EQ_EQ = 40,
  anon_sym_BANG_EQ = 41,
  anon_sym_4 = 42,
  anon_sym_per = 43,
  anon_sym_DASH = 44,
  anon_sym_BANG = 45,
  anon_sym_5 = 46,
  anon_sym_6 = 47,
  anon_sym_7 = 48,
  anon_sym_8 = 49,
  anon_sym_9 = 50,
  anon_sym_10 = 51,
  anon_sym_11 = 52,
  anon_sym_12 = 53,
  anon_sym_13 = 54,
  anon_sym_14 = 55,
  aux_sym_string_token1 = 56,
  anon_sym_DQUOTE = 57,
  sym__escape_sequence = 58,
  anon_sym_true = 59,
  anon_sym_false = 60,
  aux_sym_number_token1 = 61,
  sym_plus = 62,
  anon_sym_STAR = 63,
  anon_sym_15 = 64,
  anon_sym_16 = 65,
  anon_sym_SLASH = 66,
  anon_sym_17 = 67,
  anon_sym_STAR_STAR = 68,
  anon_sym_CARET = 69,
  sym_line_comment = 70,
  sym__string_content = 71,
  sym__float = 72,
  sym_source_file = 73,
  sym__statement = 74,
  sym__expression = 75,
  sym_factor = 76,
  sym__primary = 77,
  sym_string = 78,
  sym_boolean = 79,
  sym_number = 80,
  sym_multiply = 81,
  sym_divide = 82,
  aux_sym_source_file_repeat1 = 83,
  aux_sym_string_repeat1 = 84,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [aux_sym_source_file_token1] = "source_file_token1",
  [aux_sym_source_file_token2] = "source_file_token2",
  [sym_shebang] = "shebang",
  [anon_sym_let] = "let",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [anon_sym_fn] = "fn",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_LT] = "<",
  [anon_sym_COMMA] = ",",
  [anon_sym_GT] = ">",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_dimension] = "dimension",
  [anon_sym_AT] = "@",
  [anon_sym_metric_prefixes] = "metric_prefixes",
  [anon_sym_binary_prefixes] = "binary_prefixes",
  [anon_sym_aliases_LPAREN] = "aliases(",
  [anon_sym_long] = "long",
  [anon_sym_short] = "short",
  [anon_sym_both] = "both",
  [anon_sym_none] = "none",
  [anon_sym_unit] = "unit",
  [anon_sym_use] = "use",
  [anon_sym_COLON_COLON] = "::",
  [anon_sym_print] = "print",
  [anon_sym_assert_eq] = "assert_eq",
  [anon_sym_type] = "type",
  [anon_sym_SLASH_SLASH] = "//",
  [anon_sym_if] = "if",
  [anon_sym_then] = "then",
  [anon_sym_else] = "else",
  [anon_sym_] = "→",
  [anon_sym_to] = "to",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_2] = "≥",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_3] = "≤",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_4] = "≠",
  [anon_sym_per] = "per",
  [anon_sym_DASH] = "-",
  [anon_sym_BANG] = "!",
  [anon_sym_5] = "⁻",
  [anon_sym_6] = "¹",
  [anon_sym_7] = "²",
  [anon_sym_8] = "³",
  [anon_sym_9] = "⁴",
  [anon_sym_10] = "⁵",
  [anon_sym_11] = "⁶",
  [anon_sym_12] = "⁷",
  [anon_sym_13] = "⁸",
  [anon_sym_14] = "⁹",
  [aux_sym_string_token1] = "\"",
  [anon_sym_DQUOTE] = "\"",
  [sym__escape_sequence] = "_escape_sequence",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [aux_sym_number_token1] = "number_token1",
  [sym_plus] = "plus",
  [anon_sym_STAR] = "*",
  [anon_sym_15] = "·",
  [anon_sym_16] = "×",
  [anon_sym_SLASH] = "/",
  [anon_sym_17] = "÷",
  [anon_sym_STAR_STAR] = "**",
  [anon_sym_CARET] = "^",
  [sym_line_comment] = "line_comment",
  [sym__string_content] = "_string_content",
  [sym__float] = "_float",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym_factor] = "factor",
  [sym__primary] = "_primary",
  [sym_string] = "string",
  [sym_boolean] = "boolean",
  [sym_number] = "number",
  [sym_multiply] = "multiply",
  [sym_divide] = "divide",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [aux_sym_source_file_token1] = aux_sym_source_file_token1,
  [aux_sym_source_file_token2] = aux_sym_source_file_token2,
  [sym_shebang] = sym_shebang,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_dimension] = anon_sym_dimension,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_metric_prefixes] = anon_sym_metric_prefixes,
  [anon_sym_binary_prefixes] = anon_sym_binary_prefixes,
  [anon_sym_aliases_LPAREN] = anon_sym_aliases_LPAREN,
  [anon_sym_long] = anon_sym_long,
  [anon_sym_short] = anon_sym_short,
  [anon_sym_both] = anon_sym_both,
  [anon_sym_none] = anon_sym_none,
  [anon_sym_unit] = anon_sym_unit,
  [anon_sym_use] = anon_sym_use,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [anon_sym_print] = anon_sym_print,
  [anon_sym_assert_eq] = anon_sym_assert_eq,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_SLASH_SLASH] = anon_sym_SLASH_SLASH,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_then] = anon_sym_then,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_] = anon_sym_,
  [anon_sym_to] = anon_sym_to,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_2] = anon_sym_2,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_3] = anon_sym_3,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_4] = anon_sym_4,
  [anon_sym_per] = anon_sym_per,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_5] = anon_sym_5,
  [anon_sym_6] = anon_sym_6,
  [anon_sym_7] = anon_sym_7,
  [anon_sym_8] = anon_sym_8,
  [anon_sym_9] = anon_sym_9,
  [anon_sym_10] = anon_sym_10,
  [anon_sym_11] = anon_sym_11,
  [anon_sym_12] = anon_sym_12,
  [anon_sym_13] = anon_sym_13,
  [anon_sym_14] = anon_sym_14,
  [aux_sym_string_token1] = anon_sym_DQUOTE,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [sym__escape_sequence] = sym__escape_sequence,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [aux_sym_number_token1] = aux_sym_number_token1,
  [sym_plus] = sym_plus,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_15] = anon_sym_15,
  [anon_sym_16] = anon_sym_16,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_17] = anon_sym_17,
  [anon_sym_STAR_STAR] = anon_sym_STAR_STAR,
  [anon_sym_CARET] = anon_sym_CARET,
  [sym_line_comment] = sym_line_comment,
  [sym__string_content] = sym__string_content,
  [sym__float] = sym__float,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym_factor] = sym_factor,
  [sym__primary] = sym__primary,
  [sym_string] = sym_string,
  [sym_boolean] = sym_boolean,
  [sym_number] = sym_number,
  [sym_multiply] = sym_multiply,
  [sym_divide] = sym_divide,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_source_file_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_shebang] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_dimension] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_metric_prefixes] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_binary_prefixes] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_aliases_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_long] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_short] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_both] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_none] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_unit] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_use] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_print] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_assert_eq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_type] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_then] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_to] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_3] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_per] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_5] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_6] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_9] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_10] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_11] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_12] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_13] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_14] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym__escape_sequence] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_number_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_plus] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_15] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_17] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym__string_content] = {
    .visible = false,
    .named = true,
  },
  [sym__float] = {
    .visible = false,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_factor] = {
    .visible = true,
    .named = true,
  },
  [sym__primary] = {
    .visible = false,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_multiply] = {
    .visible = true,
    .named = true,
  },
  [sym_divide] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_left = 1,
  field_op = 2,
  field_right = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_left] = "left",
  [field_op] = "op",
  [field_right] = "right",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_left, 0},
    {field_op, 1},
    {field_right, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(17);
      if (lookahead == '\n') ADVANCE(18);
      if (lookahead == '\r') ADVANCE(3);
      if (lookahead == ' ') SKIP(14)
      if (lookahead == '!') ADVANCE(42);
      if (lookahead == '"') ADVANCE(54);
      if (lookahead == '#') ADVANCE(80);
      if (lookahead == '(') ADVANCE(27);
      if (lookahead == ')') ADVANCE(28);
      if (lookahead == '*') ADVANCE(72);
      if (lookahead == '+') ADVANCE(70);
      if (lookahead == ',') ADVANCE(25);
      if (lookahead == '-') ADVANCE(41);
      if (lookahead == '/') ADVANCE(76);
      if (lookahead == '0') ADVANCE(56);
      if (lookahead == ':') ADVANCE(21);
      if (lookahead == '<') ADVANCE(24);
      if (lookahead == '=') ADVANCE(22);
      if (lookahead == '>') ADVANCE(26);
      if (lookahead == '@') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == '^') ADVANCE(79);
      if (lookahead == 'a') ADVANCE(66);
      if (lookahead == 'b') ADVANCE(61);
      if (lookahead == 178) ADVANCE(45);
      if (lookahead == 179) ADVANCE(46);
      if (lookahead == 183) ADVANCE(73);
      if (lookahead == 185) ADVANCE(44);
      if (lookahead == 215) ADVANCE(74);
      if (lookahead == 247) ADVANCE(77);
      if (lookahead == 8308) ADVANCE(47);
      if (lookahead == 8309) ADVANCE(48);
      if (lookahead == 8310) ADVANCE(49);
      if (lookahead == 8311) ADVANCE(50);
      if (lookahead == 8312) ADVANCE(51);
      if (lookahead == 8313) ADVANCE(52);
      if (lookahead == 8315) ADVANCE(43);
      if (lookahead == 8594) ADVANCE(33);
      if (lookahead == 8800) ADVANCE(40);
      if (lookahead == 8804) ADVANCE(37);
      if (lookahead == 8805) ADVANCE(35);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(59);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(18);
      if (lookahead == ' ') SKIP(2)
      if (lookahead == '"') ADVANCE(54);
      if (lookahead == '#') ADVANCE(81);
      if (lookahead == '\\') ADVANCE(4);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(18);
      if (lookahead == ' ') SKIP(2)
      if (lookahead == '#') ADVANCE(81);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(19);
      END_STATE();
    case 4:
      if (lookahead == 'u') ADVANCE(5);
      if (lookahead == 'x') ADVANCE(12);
      if (lookahead != 0) ADVANCE(55);
      END_STATE();
    case 5:
      if (lookahead == '{') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(9);
      END_STATE();
    case 6:
      if (lookahead == '}') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(6);
      END_STATE();
    case 7:
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(57);
      END_STATE();
    case 8:
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(58);
      END_STATE();
    case 9:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(12);
      END_STATE();
    case 10:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(55);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(6);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(10);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(60);
      END_STATE();
    case 14:
      if (eof) ADVANCE(17);
      if (lookahead == '\n') ADVANCE(18);
      if (lookahead == '\r') ADVANCE(3);
      if (lookahead == ' ') SKIP(14)
      if (lookahead == '!') ADVANCE(42);
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '#') ADVANCE(80);
      if (lookahead == '(') ADVANCE(27);
      if (lookahead == ')') ADVANCE(28);
      if (lookahead == '*') ADVANCE(72);
      if (lookahead == '+') ADVANCE(70);
      if (lookahead == ',') ADVANCE(25);
      if (lookahead == '-') ADVANCE(41);
      if (lookahead == '/') ADVANCE(76);
      if (lookahead == '0') ADVANCE(56);
      if (lookahead == ':') ADVANCE(21);
      if (lookahead == '<') ADVANCE(24);
      if (lookahead == '=') ADVANCE(22);
      if (lookahead == '>') ADVANCE(26);
      if (lookahead == '@') ADVANCE(29);
      if (lookahead == '^') ADVANCE(79);
      if (lookahead == 'a') ADVANCE(66);
      if (lookahead == 'b') ADVANCE(61);
      if (lookahead == 178) ADVANCE(45);
      if (lookahead == 179) ADVANCE(46);
      if (lookahead == 183) ADVANCE(73);
      if (lookahead == 185) ADVANCE(44);
      if (lookahead == 215) ADVANCE(74);
      if (lookahead == 247) ADVANCE(77);
      if (lookahead == 8308) ADVANCE(47);
      if (lookahead == 8309) ADVANCE(48);
      if (lookahead == 8310) ADVANCE(49);
      if (lookahead == 8311) ADVANCE(50);
      if (lookahead == 8312) ADVANCE(51);
      if (lookahead == 8313) ADVANCE(52);
      if (lookahead == 8315) ADVANCE(43);
      if (lookahead == 8594) ADVANCE(33);
      if (lookahead == 8800) ADVANCE(40);
      if (lookahead == 8804) ADVANCE(37);
      if (lookahead == 8805) ADVANCE(35);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(59);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 15:
      if (eof) ADVANCE(17);
      if (lookahead == '\n') ADVANCE(19);
      if (lookahead == '\r') ADVANCE(3);
      if (lookahead == ' ') SKIP(15)
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '#') ADVANCE(80);
      if (lookahead == '0') ADVANCE(56);
      if (lookahead == 'b') ADVANCE(61);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(59);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 16:
      if (eof) ADVANCE(17);
      if (lookahead == '\n') ADVANCE(19);
      if (lookahead == '\r') ADVANCE(3);
      if (lookahead == ' ') SKIP(16)
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '#') ADVANCE(81);
      if (lookahead == '*') ADVANCE(71);
      if (lookahead == '/') ADVANCE(75);
      if (lookahead == '0') ADVANCE(56);
      if (lookahead == 'b') ADVANCE(61);
      if (lookahead == 183) ADVANCE(73);
      if (lookahead == 215) ADVANCE(74);
      if (lookahead == 247) ADVANCE(77);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(59);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym_source_file_token1);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(aux_sym_source_file_token2);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_shebang);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(31);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(38);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(36);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(34);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_aliases_LPAREN);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_2);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_3);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_4);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(23);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(39);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_5);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_6);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_7);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_8);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_9);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_10);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_11);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_12);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_13);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_14);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_string_token1);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym__escape_sequence);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'b') ADVANCE(7);
      if (lookahead == 'o') ADVANCE(8);
      if (lookahead == 'x') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(59);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(57);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(59);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '"') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '(') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(63);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_plus);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(78);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_15);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_16);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '/') ADVANCE(32);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_17);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '!') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(81);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(81);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == ' ') SKIP(0)
      if (lookahead == 'a') ADVANCE(1);
      if (lookahead == 'b') ADVANCE(2);
      if (lookahead == 'd') ADVANCE(3);
      if (lookahead == 'e') ADVANCE(4);
      if (lookahead == 'f') ADVANCE(5);
      if (lookahead == 'i') ADVANCE(6);
      if (lookahead == 'l') ADVANCE(7);
      if (lookahead == 'm') ADVANCE(8);
      if (lookahead == 'n') ADVANCE(9);
      if (lookahead == 'p') ADVANCE(10);
      if (lookahead == 's') ADVANCE(11);
      if (lookahead == 't') ADVANCE(12);
      if (lookahead == 'u') ADVANCE(13);
      END_STATE();
    case 1:
      if (lookahead == 's') ADVANCE(14);
      END_STATE();
    case 2:
      if (lookahead == 'i') ADVANCE(15);
      if (lookahead == 'o') ADVANCE(16);
      END_STATE();
    case 3:
      if (lookahead == 'i') ADVANCE(17);
      END_STATE();
    case 4:
      if (lookahead == 'l') ADVANCE(18);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(19);
      if (lookahead == 'n') ADVANCE(20);
      END_STATE();
    case 6:
      if (lookahead == 'f') ADVANCE(21);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(22);
      if (lookahead == 'o') ADVANCE(23);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 9:
      if (lookahead == 'o') ADVANCE(25);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(26);
      if (lookahead == 'r') ADVANCE(27);
      END_STATE();
    case 11:
      if (lookahead == 'h') ADVANCE(28);
      END_STATE();
    case 12:
      if (lookahead == 'h') ADVANCE(29);
      if (lookahead == 'o') ADVANCE(30);
      if (lookahead == 'r') ADVANCE(31);
      if (lookahead == 'y') ADVANCE(32);
      END_STATE();
    case 13:
      if (lookahead == 'n') ADVANCE(33);
      if (lookahead == 's') ADVANCE(34);
      END_STATE();
    case 14:
      if (lookahead == 's') ADVANCE(35);
      END_STATE();
    case 15:
      if (lookahead == 'n') ADVANCE(36);
      END_STATE();
    case 16:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 17:
      if (lookahead == 'm') ADVANCE(38);
      END_STATE();
    case 18:
      if (lookahead == 's') ADVANCE(39);
      END_STATE();
    case 19:
      if (lookahead == 'l') ADVANCE(40);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 22:
      if (lookahead == 't') ADVANCE(41);
      END_STATE();
    case 23:
      if (lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 24:
      if (lookahead == 't') ADVANCE(43);
      END_STATE();
    case 25:
      if (lookahead == 'n') ADVANCE(44);
      END_STATE();
    case 26:
      if (lookahead == 'r') ADVANCE(45);
      END_STATE();
    case 27:
      if (lookahead == 'i') ADVANCE(46);
      END_STATE();
    case 28:
      if (lookahead == 'o') ADVANCE(47);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_to);
      END_STATE();
    case 31:
      if (lookahead == 'u') ADVANCE(49);
      END_STATE();
    case 32:
      if (lookahead == 'p') ADVANCE(50);
      END_STATE();
    case 33:
      if (lookahead == 'i') ADVANCE(51);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(53);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(54);
      END_STATE();
    case 37:
      if (lookahead == 'h') ADVANCE(55);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(56);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(57);
      END_STATE();
    case 40:
      if (lookahead == 's') ADVANCE(58);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 42:
      if (lookahead == 'g') ADVANCE(59);
      END_STATE();
    case 43:
      if (lookahead == 'r') ADVANCE(60);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(61);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_per);
      END_STATE();
    case 46:
      if (lookahead == 'n') ADVANCE(62);
      END_STATE();
    case 47:
      if (lookahead == 'r') ADVANCE(63);
      END_STATE();
    case 48:
      if (lookahead == 'n') ADVANCE(64);
      END_STATE();
    case 49:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 51:
      if (lookahead == 't') ADVANCE(67);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_use);
      END_STATE();
    case 53:
      if (lookahead == 'r') ADVANCE(68);
      END_STATE();
    case 54:
      if (lookahead == 'r') ADVANCE(69);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_both);
      END_STATE();
    case 56:
      if (lookahead == 'n') ADVANCE(70);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 58:
      if (lookahead == 'e') ADVANCE(71);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_long);
      END_STATE();
    case 60:
      if (lookahead == 'i') ADVANCE(72);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_none);
      END_STATE();
    case 62:
      if (lookahead == 't') ADVANCE(73);
      END_STATE();
    case 63:
      if (lookahead == 't') ADVANCE(74);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_then);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_unit);
      END_STATE();
    case 68:
      if (lookahead == 't') ADVANCE(75);
      END_STATE();
    case 69:
      if (lookahead == 'y') ADVANCE(76);
      END_STATE();
    case 70:
      if (lookahead == 's') ADVANCE(77);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 72:
      if (lookahead == 'c') ADVANCE(78);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_print);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_short);
      END_STATE();
    case 75:
      if (lookahead == '_') ADVANCE(79);
      END_STATE();
    case 76:
      if (lookahead == '_') ADVANCE(80);
      END_STATE();
    case 77:
      if (lookahead == 'i') ADVANCE(81);
      END_STATE();
    case 78:
      if (lookahead == '_') ADVANCE(82);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(83);
      END_STATE();
    case 80:
      if (lookahead == 'p') ADVANCE(84);
      END_STATE();
    case 81:
      if (lookahead == 'o') ADVANCE(85);
      END_STATE();
    case 82:
      if (lookahead == 'p') ADVANCE(86);
      END_STATE();
    case 83:
      if (lookahead == 'q') ADVANCE(87);
      END_STATE();
    case 84:
      if (lookahead == 'r') ADVANCE(88);
      END_STATE();
    case 85:
      if (lookahead == 'n') ADVANCE(89);
      END_STATE();
    case 86:
      if (lookahead == 'r') ADVANCE(90);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_assert_eq);
      END_STATE();
    case 88:
      if (lookahead == 'e') ADVANCE(91);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_dimension);
      END_STATE();
    case 90:
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 91:
      if (lookahead == 'f') ADVANCE(93);
      END_STATE();
    case 92:
      if (lookahead == 'f') ADVANCE(94);
      END_STATE();
    case 93:
      if (lookahead == 'i') ADVANCE(95);
      END_STATE();
    case 94:
      if (lookahead == 'i') ADVANCE(96);
      END_STATE();
    case 95:
      if (lookahead == 'x') ADVANCE(97);
      END_STATE();
    case 96:
      if (lookahead == 'x') ADVANCE(98);
      END_STATE();
    case 97:
      if (lookahead == 'e') ADVANCE(99);
      END_STATE();
    case 98:
      if (lookahead == 'e') ADVANCE(100);
      END_STATE();
    case 99:
      if (lookahead == 's') ADVANCE(101);
      END_STATE();
    case 100:
      if (lookahead == 's') ADVANCE(102);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_binary_prefixes);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_metric_prefixes);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 15, .external_lex_state = 2},
  [2] = {.lex_state = 16, .external_lex_state = 2},
  [3] = {.lex_state = 16, .external_lex_state = 2},
  [4] = {.lex_state = 16, .external_lex_state = 2},
  [5] = {.lex_state = 16, .external_lex_state = 2},
  [6] = {.lex_state = 16, .external_lex_state = 2},
  [7] = {.lex_state = 16},
  [8] = {.lex_state = 16, .external_lex_state = 2},
  [9] = {.lex_state = 16},
  [10] = {.lex_state = 16},
  [11] = {.lex_state = 16},
  [12] = {.lex_state = 16},
  [13] = {.lex_state = 16, .external_lex_state = 2},
  [14] = {.lex_state = 16, .external_lex_state = 2},
  [15] = {.lex_state = 16},
  [16] = {.lex_state = 1, .external_lex_state = 3},
  [17] = {.lex_state = 1, .external_lex_state = 3},
  [18] = {.lex_state = 1, .external_lex_state = 3},
  [19] = {.lex_state = 16},
  [20] = {.lex_state = 16},
  [21] = {.lex_state = 1},
};

enum {
  ts_external_token__string_content = 0,
  ts_external_token__float = 1,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__string_content] = sym__string_content,
  [ts_external_token__float] = sym__float,
};

static const bool ts_external_scanner_states[4][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__string_content] = true,
    [ts_external_token__float] = true,
  },
  [2] = {
    [ts_external_token__float] = true,
  },
  [3] = {
    [ts_external_token__string_content] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [aux_sym_source_file_token1] = ACTIONS(1),
    [aux_sym_source_file_token2] = ACTIONS(1),
    [sym_shebang] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_dimension] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_metric_prefixes] = ACTIONS(1),
    [anon_sym_binary_prefixes] = ACTIONS(1),
    [anon_sym_aliases_LPAREN] = ACTIONS(1),
    [anon_sym_long] = ACTIONS(1),
    [anon_sym_short] = ACTIONS(1),
    [anon_sym_both] = ACTIONS(1),
    [anon_sym_none] = ACTIONS(1),
    [anon_sym_unit] = ACTIONS(1),
    [anon_sym_use] = ACTIONS(1),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [anon_sym_print] = ACTIONS(1),
    [anon_sym_assert_eq] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_SLASH_SLASH] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_then] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [anon_sym_to] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_2] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_3] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_4] = ACTIONS(1),
    [anon_sym_per] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_5] = ACTIONS(1),
    [anon_sym_6] = ACTIONS(1),
    [anon_sym_7] = ACTIONS(1),
    [anon_sym_8] = ACTIONS(1),
    [anon_sym_9] = ACTIONS(1),
    [anon_sym_10] = ACTIONS(1),
    [anon_sym_11] = ACTIONS(1),
    [anon_sym_12] = ACTIONS(1),
    [anon_sym_13] = ACTIONS(1),
    [anon_sym_14] = ACTIONS(1),
    [aux_sym_string_token1] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym__escape_sequence] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [aux_sym_number_token1] = ACTIONS(1),
    [sym_plus] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_15] = ACTIONS(1),
    [anon_sym_16] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_17] = ACTIONS(1),
    [anon_sym_STAR_STAR] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [sym_line_comment] = ACTIONS(3),
    [sym__string_content] = ACTIONS(1),
    [sym__float] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(20),
    [sym__statement] = STATE(19),
    [sym__expression] = STATE(9),
    [sym_factor] = STATE(9),
    [sym__primary] = STATE(9),
    [sym_string] = STATE(9),
    [sym_boolean] = STATE(9),
    [sym_number] = STATE(9),
    [aux_sym_source_file_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [aux_sym_source_file_token2] = ACTIONS(9),
    [sym_shebang] = ACTIONS(11),
    [aux_sym_string_token1] = ACTIONS(13),
    [anon_sym_true] = ACTIONS(15),
    [anon_sym_false] = ACTIONS(15),
    [aux_sym_number_token1] = ACTIONS(17),
    [sym_line_comment] = ACTIONS(3),
    [sym__float] = ACTIONS(17),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(13), 1,
      aux_sym_string_token1,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(21), 1,
      aux_sym_source_file_token2,
    ACTIONS(23), 1,
      sym_line_comment,
    STATE(3), 1,
      aux_sym_source_file_repeat1,
    STATE(19), 1,
      sym__statement,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(17), 2,
      sym__float,
      aux_sym_number_token1,
    STATE(9), 6,
      sym__expression,
      sym_factor,
      sym__primary,
      sym_string,
      sym_boolean,
      sym_number,
  [38] = 10,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(13), 1,
      aux_sym_string_token1,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
    ACTIONS(27), 1,
      aux_sym_source_file_token2,
    STATE(4), 1,
      aux_sym_source_file_repeat1,
    STATE(19), 1,
      sym__statement,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(17), 2,
      sym__float,
      aux_sym_number_token1,
    STATE(9), 6,
      sym__expression,
      sym_factor,
      sym__primary,
      sym_string,
      sym_boolean,
      sym_number,
  [76] = 10,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
    ACTIONS(31), 1,
      sym_identifier,
    ACTIONS(34), 1,
      aux_sym_source_file_token2,
    ACTIONS(37), 1,
      aux_sym_string_token1,
    STATE(4), 1,
      aux_sym_source_file_repeat1,
    STATE(19), 1,
      sym__statement,
    ACTIONS(40), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(43), 2,
      sym__float,
      aux_sym_number_token1,
    STATE(9), 6,
      sym__expression,
      sym_factor,
      sym__primary,
      sym_string,
      sym_boolean,
      sym_number,
  [114] = 10,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(13), 1,
      aux_sym_string_token1,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(27), 1,
      aux_sym_source_file_token2,
    ACTIONS(46), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      aux_sym_source_file_repeat1,
    STATE(19), 1,
      sym__statement,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(17), 2,
      sym__float,
      aux_sym_number_token1,
    STATE(9), 6,
      sym__expression,
      sym_factor,
      sym__primary,
      sym_string,
      sym_boolean,
      sym_number,
  [152] = 6,
    ACTIONS(13), 1,
      aux_sym_string_token1,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(48), 1,
      sym_identifier,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(17), 2,
      sym__float,
      aux_sym_number_token1,
    STATE(7), 6,
      sym__expression,
      sym_factor,
      sym__primary,
      sym_string,
      sym_boolean,
      sym_number,
  [178] = 3,
    ACTIONS(23), 1,
      sym_line_comment,
    STATE(6), 2,
      sym_multiply,
      sym_divide,
    ACTIONS(50), 6,
      aux_sym_source_file_token2,
      anon_sym_STAR,
      anon_sym_15,
      anon_sym_16,
      anon_sym_SLASH,
      anon_sym_17,
  [194] = 3,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(52), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
    ACTIONS(29), 5,
      sym__float,
      ts_builtin_sym_end,
      aux_sym_source_file_token2,
      aux_sym_string_token1,
      aux_sym_number_token1,
  [210] = 5,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(54), 1,
      aux_sym_source_file_token2,
    ACTIONS(58), 2,
      anon_sym_SLASH,
      anon_sym_17,
    STATE(6), 2,
      sym_multiply,
      sym_divide,
    ACTIONS(56), 3,
      anon_sym_STAR,
      anon_sym_15,
      anon_sym_16,
  [230] = 2,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(60), 6,
      aux_sym_source_file_token2,
      anon_sym_STAR,
      anon_sym_15,
      anon_sym_16,
      anon_sym_SLASH,
      anon_sym_17,
  [242] = 2,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(62), 6,
      aux_sym_source_file_token2,
      anon_sym_STAR,
      anon_sym_15,
      anon_sym_16,
      anon_sym_SLASH,
      anon_sym_17,
  [254] = 2,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(64), 6,
      aux_sym_source_file_token2,
      anon_sym_STAR,
      anon_sym_15,
      anon_sym_16,
      anon_sym_SLASH,
      anon_sym_17,
  [266] = 3,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(66), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
    ACTIONS(68), 3,
      sym__float,
      aux_sym_string_token1,
      aux_sym_number_token1,
  [280] = 3,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(70), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
    ACTIONS(72), 3,
      sym__float,
      aux_sym_string_token1,
      aux_sym_number_token1,
  [294] = 2,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(74), 6,
      aux_sym_source_file_token2,
      anon_sym_STAR,
      anon_sym_15,
      anon_sym_16,
      anon_sym_SLASH,
      anon_sym_17,
  [306] = 4,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(76), 1,
      anon_sym_DQUOTE,
    STATE(18), 1,
      aux_sym_string_repeat1,
    ACTIONS(78), 2,
      sym__string_content,
      sym__escape_sequence,
  [320] = 4,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(80), 1,
      anon_sym_DQUOTE,
    STATE(16), 1,
      aux_sym_string_repeat1,
    ACTIONS(82), 2,
      sym__string_content,
      sym__escape_sequence,
  [334] = 4,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    STATE(18), 1,
      aux_sym_string_repeat1,
    ACTIONS(86), 2,
      sym__string_content,
      sym__escape_sequence,
  [348] = 2,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(89), 1,
      aux_sym_source_file_token2,
  [355] = 2,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(91), 1,
      ts_builtin_sym_end,
  [362] = 2,
    ACTIONS(23), 1,
      sym_line_comment,
    ACTIONS(93), 1,
      aux_sym_source_file_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 38,
  [SMALL_STATE(4)] = 76,
  [SMALL_STATE(5)] = 114,
  [SMALL_STATE(6)] = 152,
  [SMALL_STATE(7)] = 178,
  [SMALL_STATE(8)] = 194,
  [SMALL_STATE(9)] = 210,
  [SMALL_STATE(10)] = 230,
  [SMALL_STATE(11)] = 242,
  [SMALL_STATE(12)] = 254,
  [SMALL_STATE(13)] = 266,
  [SMALL_STATE(14)] = 280,
  [SMALL_STATE(15)] = 294,
  [SMALL_STATE(16)] = 306,
  [SMALL_STATE(17)] = 320,
  [SMALL_STATE(18)] = 334,
  [SMALL_STATE(19)] = 348,
  [SMALL_STATE(20)] = 355,
  [SMALL_STATE(21)] = 362,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(17),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(12),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_factor, 3, .production_id = 1),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1),
  [66] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_multiply, 1),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiply, 1),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_divide, 1),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_divide, 1),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(18),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [91] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_numbat_external_scanner_create(void);
void tree_sitter_numbat_external_scanner_destroy(void *);
bool tree_sitter_numbat_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_numbat_external_scanner_serialize(void *, char *);
void tree_sitter_numbat_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_numbat(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_numbat_external_scanner_create,
      tree_sitter_numbat_external_scanner_destroy,
      tree_sitter_numbat_external_scanner_scan,
      tree_sitter_numbat_external_scanner_serialize,
      tree_sitter_numbat_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
