#include <tree_sitter/parser.h>
#include <stdio.h>
#include <wctype.h>

enum TokenType {
  STRING_CONTENT,
  FLOAT,
};

void *tree_sitter_numbat_external_scanner_create() { return NULL; }
void tree_sitter_numbat_external_scanner_destroy(void *p) {}
void tree_sitter_numbat_external_scanner_reset(void *p) {}
unsigned tree_sitter_numbat_external_scanner_serialize(void *p, char *buffer) { return 0; }
void tree_sitter_numbat_external_scanner_deserialize(void *p, const char *b, unsigned n) {}

static void advance(TSLexer *lexer) {
  lexer->advance(lexer, false);
}

static bool is_num_char(int32_t c) {
  return c == '_' || iswdigit(c);
}

bool tree_sitter_numbat_external_scanner_scan(void *payload, TSLexer *lexer,
                                            const bool *valid_symbols) {

  while (iswspace(lexer->lookahead)) lexer->advance(lexer, true);
  
  if (valid_symbols[STRING_CONTENT] && !valid_symbols[FLOAT]) {
    bool has_content = false;
    for (;;) {
      if (lexer->lookahead == '\"' || lexer->lookahead == '\\') {
        break;
      } else if (lexer->lookahead == 0) {
        return false;
      }
      has_content = true;
      advance(lexer);
    }
    lexer->result_symbol = STRING_CONTENT;
    return has_content;
  }

  if (valid_symbols[FLOAT] && (iswdigit(lexer->lookahead) || lexer->lookahead == '.')) {
    bool has_fraction = false, has_exponent = false;
    lexer->result_symbol = FLOAT;

    // If the float looks like 12.13
    // we can skip all the numbers until we reach the dot
    if (lexer->lookahead != '.') {
      while (is_num_char(lexer->lookahead)) advance(lexer);
    }
    // Else if it look like .13 => nothing to do

    // Once we reach this point, we must have either a point or a scientific writing
    
    // Parsing the point if there is one, both 12.13 and .13 should validate this condition
    if (lexer->lookahead == '.') {
      has_fraction = true;
      advance(lexer); // skip the point
      if (iswalpha(lexer->lookahead)) {
          // The dot is followed by a letter: 1.max(2) => not a float but an integer
          return false;
      }

      if (lexer->lookahead == '.') return false;
      while (is_num_char(lexer->lookahead)) advance(lexer);
    }

    lexer->mark_end(lexer);

    if (lexer->lookahead == 'e' || lexer->lookahead == 'E') {
      has_exponent = true;
      advance(lexer);
      if (lexer->lookahead == '+' || lexer->lookahead == '-') {
        advance(lexer);
      }
      if (!is_num_char(lexer->lookahead)) return true;
      advance(lexer);

      while (is_num_char(lexer->lookahead)) advance(lexer);

      lexer->mark_end(lexer);
    }

    if (!(has_exponent || has_fraction)) return false;

    lexer->mark_end(lexer);
    return true;
  }

  return false;
}
