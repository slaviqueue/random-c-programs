#include "token.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "common.h"
#include "io.h"

static bool isarithmeticop(char c);

TokenType token_read_to(char* buffer) {
  char current;

  while (isspace(current = io_getch()))
    ;

  if (current == EOF)
    return TOKEN_EOF;

  if (isdigit(current)) {
    *buffer++ = current;

    while (isdigit(current = io_getch()))
      *buffer++ = current;

    if (current == '.') {
      *buffer++ = '.';

      while (isdigit(current = io_getch()))
        *buffer++ = current;
    }

    if (current == 'e') {
      *buffer++ = 'e';

      if ((current = io_getch()) == '-')
        *buffer++ = '-';
      else
        io_ungetch(current);

      while (isdigit(current = io_getch()))
        *buffer++ = current;
    }

    io_ungetch(current);
    *buffer = '\0';
    return TOKEN_NUMBER;
  }

  if (isalpha(current)) {
    *buffer++ = current;
    while (isalpha(current = io_getch()) || isdigit(current))
      *buffer++ = current;

    io_ungetch(current);
    *buffer = '\0';
    return TOKEN_OPERATION;
  }

  if (isarithmeticop(current)) {
    *buffer++ = current;
    *buffer = '\0';
    return TOKEN_OPERATION;
  }

  *buffer = '\0';
  return TOKEN_UNKNOWN;
}

static bool isarithmeticop(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}
