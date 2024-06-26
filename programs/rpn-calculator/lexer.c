#include "lexer.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "io.h"

static bool is_arithmetic_op(char c);

static Token emit_token(TokenType type, Lexer* lexer);
static bool matches(Lexer* lexer, char c);
static void eat_one(Lexer* lexer);
static char advance_one(Lexer* lexer);
static char current(Lexer* lexer);
static void revert(Lexer* lexer);
static void put(Lexer* lexer, char c);

static Token match_number(Lexer* lexer);

Token lexer_next_token(Lexer* lexer) {
  lexer->_buffpos = lexer->_buffer;

  while (isblank(advance_one(lexer)) && current(lexer) != '\n')
    ;

  if (matches(lexer, '\n'))
    return emit_token(TOKEN_NEWLINE, lexer);

  if (matches(lexer, EOF))
    return emit_token(TOKEN_EOF, lexer);

  if (isdigit(current(lexer))) {
    return match_number(lexer);
  }

  if (matches(lexer, '-')) {
    if (isdigit(advance_one(lexer))) {
      put(lexer, '-');
      return match_number(lexer);
    }

    revert(lexer);
  }

  if (isalpha(current(lexer))) {
    eat_one(lexer);

    while (isalpha(advance_one(lexer)) || isdigit(current(lexer)))
      eat_one(lexer);

    revert(lexer);
    *lexer->_buffpos = '\0';
    return emit_token(TOKEN_OPERATION, lexer);
  }

  if (is_arithmetic_op(current(lexer))) {
    eat_one(lexer);
    put(lexer, '\0');
    return emit_token(TOKEN_OPERATION, lexer);
  }

  put(lexer, '\0');
  return emit_token(TOKEN_UNKNOWN, lexer);
}

Lexer lexer_make() {
  Lexer lexer;
  lexer._current = '\0';
  lexer._buffpos = lexer._buffer;
  memset(lexer._buffer, 0, BUFSIZ * sizeof(char));

  return lexer;
}

static bool is_arithmetic_op(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

static Token emit_token(TokenType type, Lexer* lexer) {
  Token token = {.type = type, .value = lexer->_buffer};
  return token;
}

static bool matches(Lexer* lexer, char c) {
  return lexer->_current == c;
}

static void eat_one(Lexer* lexer) {
  *lexer->_buffpos++ = lexer->_current;
}

static char current(Lexer* lexer) {
  return lexer->_current;
}

static char advance_one(Lexer* lexer) {
  return lexer->_current = io_getch();
}

static void revert(Lexer* lexer) {
  io_ungetch(current(lexer));
}

static void put(Lexer* lexer, char c) {
  *lexer->_buffpos++ = c;
}

static Token match_number(Lexer* lexer) {
  eat_one(lexer);

  while (isdigit(advance_one(lexer)))
    eat_one(lexer);

  if (matches(lexer, '.')) {
    eat_one(lexer);

    while (isdigit(advance_one(lexer)))
      eat_one(lexer);
  }

  if (matches(lexer, 'e')) {
    eat_one(lexer);

    if ((advance_one(lexer)) == '-')
      eat_one(lexer);
    else
      revert(lexer);

    while (isdigit(advance_one(lexer)))
      eat_one(lexer);
  }

  revert(lexer);
  put(lexer, '\0');
  return emit_token(TOKEN_NUMBER, lexer);
}
