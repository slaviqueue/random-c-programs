#include "getword.h"
#include <ctype.h>
#include <stdio.h>

char* getword(char* buf, int max_len, int* line_number) {
  char* buf_start = buf;
  char current_char;

  while (isspace(current_char = getc(stdin)))
    if (current_char == '\n')
      (*line_number)++;

  if (current_char == EOF)
    return NULL;

  *buf++ = current_char;

  if (!isalpha(current_char)) {
    *buf = '\0';
    return buf_start;
  }

  while (isalnum(current_char = getc(stdin)) && max_len--)
    *buf++ = current_char;

  ungetc(current_char, stdin);
  *buf = '\0';

  return buf_start;
}
