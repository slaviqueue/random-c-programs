#include <math.h>
#include <stdio.h>

double atofs(char* str) {
  int sign = 1;

  while (*str == '\t' || *str == ' ')
    str++;

  if (*str == '-')
    sign = -1;

  if (*str == '-' || *str == '+')
    str++;

  double result = 0;

  for (; *str != '.' && *str != 'e' && *str != '\0'; str++) {
    result = result * 10 + *str - '0';
  }

  if (*str == '\0')
    return result;

  if (*str == '.')
    str++;

  int order = 1;

  for (; *str != 'e' && *str != '\0'; str++) {
    order *= 10;
    result = result * 10 + *str - '0';
  }

  result /= order;

  if (*str == '\0')
    return result;

  if (*str == 'e')
    str++;

  int exponent = 0;
  int exponent_sign = 1;

  if (*str == '-')
    exponent_sign = -1;

  if (*str == '-' || *str == '+')
    str++;

  for (; *str != '\0'; str++)
    exponent = exponent * 10 + *str - '0';

  result *= pow(10, exponent * exponent_sign);

  return result;
}
