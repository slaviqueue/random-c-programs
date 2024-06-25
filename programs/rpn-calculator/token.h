#pragma once

typedef enum {
  TOKEN_UNKNOWN,
  TOKEN_EOF,
  TOKEN_NUMBER,
  TOKEN_OPERATION,
} TokenType;

TokenType token_read_to(char* buffer);
