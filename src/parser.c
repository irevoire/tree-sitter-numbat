#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 16
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 21
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 2

enum {
  aux_sym_source_file_token1 = 1,
  aux_sym_source_file_token2 = 2,
  sym_shebang = 3,
  anon_sym_STAR = 4,
  anon_sym_ = 5,
  anon_sym_2 = 6,
  anon_sym_SLASH = 7,
  anon_sym_3 = 8,
  sym_line_comment = 9,
  sym__string_content = 10,
  sym__float = 11,
  sym_source_file = 12,
  sym__statement = 13,
  sym__expression = 14,
  sym_factor = 15,
  sym__primary = 16,
  sym_number = 17,
  sym_multiply = 18,
  sym_divide = 19,
  aux_sym_source_file_repeat1 = 20,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_source_file_token1] = "source_file_token1",
  [aux_sym_source_file_token2] = "source_file_token2",
  [sym_shebang] = "shebang",
  [anon_sym_STAR] = "*",
  [anon_sym_] = "·",
  [anon_sym_2] = "×",
  [anon_sym_SLASH] = "/",
  [anon_sym_3] = "÷",
  [sym_line_comment] = "line_comment",
  [sym__string_content] = "_string_content",
  [sym__float] = "_float",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym_factor] = "factor",
  [sym__primary] = "_primary",
  [sym_number] = "number",
  [sym_multiply] = "multiply",
  [sym_divide] = "divide",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_source_file_token1] = aux_sym_source_file_token1,
  [aux_sym_source_file_token2] = aux_sym_source_file_token2,
  [sym_shebang] = sym_shebang,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_] = anon_sym_,
  [anon_sym_2] = anon_sym_2,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_3] = anon_sym_3,
  [sym_line_comment] = sym_line_comment,
  [sym__string_content] = sym__string_content,
  [sym__float] = sym__float,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym_factor] = sym_factor,
  [sym__primary] = sym__primary,
  [sym_number] = sym_number,
  [sym_multiply] = sym_multiply,
  [sym_divide] = sym_divide,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
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
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_3] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(5);
      if (lookahead == '\n') ADVANCE(6);
      if (lookahead == '\r') ADVANCE(2);
      if (lookahead == ' ') SKIP(0)
      if (lookahead == '#') ADVANCE(14);
      if (lookahead == '*') ADVANCE(9);
      if (lookahead == '/') ADVANCE(12);
      if (lookahead == 183) ADVANCE(10);
      if (lookahead == 215) ADVANCE(11);
      if (lookahead == 247) ADVANCE(13);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(6);
      if (lookahead == ' ') SKIP(1)
      if (lookahead == '#') ADVANCE(15);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(7);
      END_STATE();
    case 3:
      if (eof) ADVANCE(5);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\r') ADVANCE(2);
      if (lookahead == ' ') SKIP(3)
      if (lookahead == '#') ADVANCE(14);
      END_STATE();
    case 4:
      if (eof) ADVANCE(5);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\r') ADVANCE(2);
      if (lookahead == ' ') SKIP(4)
      if (lookahead == '#') ADVANCE(15);
      if (lookahead == '*') ADVANCE(9);
      if (lookahead == '/') ADVANCE(12);
      if (lookahead == 183) ADVANCE(10);
      if (lookahead == 215) ADVANCE(11);
      if (lookahead == 247) ADVANCE(13);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(aux_sym_source_file_token1);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(aux_sym_source_file_token2);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_shebang);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_2);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_3);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '!') ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(15);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(15);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 3, .external_lex_state = 2},
  [2] = {.lex_state = 4, .external_lex_state = 2},
  [3] = {.lex_state = 4, .external_lex_state = 2},
  [4] = {.lex_state = 4, .external_lex_state = 2},
  [5] = {.lex_state = 4, .external_lex_state = 2},
  [6] = {.lex_state = 4},
  [7] = {.lex_state = 4},
  [8] = {.lex_state = 4},
  [9] = {.lex_state = 4, .external_lex_state = 2},
  [10] = {.lex_state = 4, .external_lex_state = 2},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 4},
  [13] = {.lex_state = 4},
  [14] = {.lex_state = 4, .external_lex_state = 2},
  [15] = {.lex_state = 4, .external_lex_state = 2},
};

enum {
  ts_external_token__string_content = 0,
  ts_external_token__float = 1,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__string_content] = sym__string_content,
  [ts_external_token__float] = sym__float,
};

static const bool ts_external_scanner_states[3][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__string_content] = true,
    [ts_external_token__float] = true,
  },
  [2] = {
    [ts_external_token__float] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym_source_file_token1] = ACTIONS(1),
    [aux_sym_source_file_token2] = ACTIONS(1),
    [sym_shebang] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [anon_sym_2] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_3] = ACTIONS(1),
    [sym_line_comment] = ACTIONS(3),
    [sym__string_content] = ACTIONS(1),
    [sym__float] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(12),
    [sym__statement] = STATE(13),
    [sym__expression] = STATE(6),
    [sym_factor] = STATE(6),
    [sym__primary] = STATE(6),
    [sym_number] = STATE(6),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(5),
    [aux_sym_source_file_token2] = ACTIONS(7),
    [sym_shebang] = ACTIONS(9),
    [sym_line_comment] = ACTIONS(3),
    [sym__float] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(11), 1,
      sym__float,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    ACTIONS(15), 1,
      aux_sym_source_file_token2,
    ACTIONS(17), 1,
      sym_line_comment,
    STATE(4), 1,
      aux_sym_source_file_repeat1,
    STATE(13), 1,
      sym__statement,
    STATE(6), 4,
      sym__expression,
      sym_factor,
      sym__primary,
      sym_number,
  [25] = 7,
    ACTIONS(11), 1,
      sym__float,
    ACTIONS(17), 1,
      sym_line_comment,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(21), 1,
      aux_sym_source_file_token2,
    STATE(5), 1,
      aux_sym_source_file_repeat1,
    STATE(13), 1,
      sym__statement,
    STATE(6), 4,
      sym__expression,
      sym_factor,
      sym__primary,
      sym_number,
  [50] = 7,
    ACTIONS(17), 1,
      sym_line_comment,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    ACTIONS(25), 1,
      aux_sym_source_file_token2,
    ACTIONS(28), 1,
      sym__float,
    STATE(4), 1,
      aux_sym_source_file_repeat1,
    STATE(13), 1,
      sym__statement,
    STATE(6), 4,
      sym__expression,
      sym_factor,
      sym__primary,
      sym_number,
  [75] = 7,
    ACTIONS(11), 1,
      sym__float,
    ACTIONS(15), 1,
      aux_sym_source_file_token2,
    ACTIONS(17), 1,
      sym_line_comment,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      aux_sym_source_file_repeat1,
    STATE(13), 1,
      sym__statement,
    STATE(6), 4,
      sym__expression,
      sym_factor,
      sym__primary,
      sym_number,
  [100] = 5,
    ACTIONS(17), 1,
      sym_line_comment,
    ACTIONS(33), 1,
      aux_sym_source_file_token2,
    ACTIONS(37), 2,
      anon_sym_SLASH,
      anon_sym_3,
    STATE(9), 2,
      sym_multiply,
      sym_divide,
    ACTIONS(35), 3,
      anon_sym_STAR,
      anon_sym_,
      anon_sym_2,
  [120] = 3,
    ACTIONS(17), 1,
      sym_line_comment,
    STATE(9), 2,
      sym_multiply,
      sym_divide,
    ACTIONS(39), 6,
      aux_sym_source_file_token2,
      anon_sym_STAR,
      anon_sym_,
      anon_sym_2,
      anon_sym_SLASH,
      anon_sym_3,
  [136] = 2,
    ACTIONS(17), 1,
      sym_line_comment,
    ACTIONS(41), 6,
      aux_sym_source_file_token2,
      anon_sym_STAR,
      anon_sym_,
      anon_sym_2,
      anon_sym_SLASH,
      anon_sym_3,
  [148] = 3,
    ACTIONS(11), 1,
      sym__float,
    ACTIONS(17), 1,
      sym_line_comment,
    STATE(7), 4,
      sym__expression,
      sym_factor,
      sym__primary,
      sym_number,
  [161] = 2,
    ACTIONS(17), 1,
      sym_line_comment,
    ACTIONS(23), 3,
      sym__float,
      ts_builtin_sym_end,
      aux_sym_source_file_token2,
  [170] = 2,
    ACTIONS(17), 1,
      sym_line_comment,
    ACTIONS(43), 1,
      aux_sym_source_file_token1,
  [177] = 2,
    ACTIONS(17), 1,
      sym_line_comment,
    ACTIONS(45), 1,
      ts_builtin_sym_end,
  [184] = 2,
    ACTIONS(17), 1,
      sym_line_comment,
    ACTIONS(47), 1,
      aux_sym_source_file_token2,
  [191] = 2,
    ACTIONS(17), 1,
      sym_line_comment,
    ACTIONS(49), 1,
      sym__float,
  [198] = 2,
    ACTIONS(17), 1,
      sym_line_comment,
    ACTIONS(51), 1,
      sym__float,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 25,
  [SMALL_STATE(4)] = 50,
  [SMALL_STATE(5)] = 75,
  [SMALL_STATE(6)] = 100,
  [SMALL_STATE(7)] = 120,
  [SMALL_STATE(8)] = 136,
  [SMALL_STATE(9)] = 148,
  [SMALL_STATE(10)] = 161,
  [SMALL_STATE(11)] = 170,
  [SMALL_STATE(12)] = 177,
  [SMALL_STATE(13)] = 184,
  [SMALL_STATE(14)] = 191,
  [SMALL_STATE(15)] = 198,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(8),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_factor, 3, .production_id = 1),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [45] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiply, 1),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_divide, 1),
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
