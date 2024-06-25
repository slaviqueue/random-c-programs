#pragma once

typedef enum {
  TOKEN_UNKNOWN,
  TOKEN_EOF,
  TOKEN_NEWLINE,
  TOKEN_NUMBER,
  TOKEN_OPERATION,
} TokenType;

TokenType getop(char* buffer);
