#include "getint.h"
#include <ctype.h>
#include <stdio.h>
#include "common.h"

int getint(int* result) {
  char current;

  while (isspace(current = getc(stdin)))
    ;

  int sign = 1;

  if (current == '-')
    sign = -1;

  if (current == '-' || current == '+')
    current = getc(stdin);

  if (!isdigit(current)) {
    ungetc(current, stdin);
    return GetIntStatusNotANumber;
  }

  *result = 0;

  do {
    *result = *result * 10 + current - '0';
  } while (isdigit(current = getc(stdin)));

  *result *= sign;

  ungetc(current, stdin);

  return GetIntStatusNumberFound;
}
