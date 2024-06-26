#pragma once

#include <stdio.h>
typedef enum {
  TOKEN_UNKNOWN,
  TOKEN_EOF,
  TOKEN_NEWLINE,
  TOKEN_NUMBER,
  TOKEN_OPERATION,
} TokenType;

typedef struct {
  TokenType type;
  char* value;
} Token;

typedef struct {
  char _buffer[BUFSIZ];
  char* _buffpos;
  char _current;
} Lexer;

Lexer lexer_make();
Token lexer_next_token(Lexer* lexer);
