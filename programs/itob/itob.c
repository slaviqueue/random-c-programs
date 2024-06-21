#include <string.h>

static inline char get_digit_in_base(int n, int base);
static inline char* reverse(char* s1);

char* itob(int n, char* s, int b) {
  char* s_start = s;
  int sign = n;

  if (n < 0)
    n *= -1;

  do {
    *(s++) = get_digit_in_base(n % b, b);
  } while ((n /= b) > 0);

  if (sign < 0)
    *(s++) = '-';

  *s = '\0';

  reverse(s_start);

  return s_start;
}

static char* reverse(char* s1) {
  int len = strlen(s1);

  for (int i = 0; i < len / 2; i++) {
    char left = s1[i];
    s1[i] = s1[len - 1 - i];
    s1[len - 1 - i] = left;
  }

  return s1;
}

static inline char get_digit_in_base(int n, int base) {
  n %= base;

  if (n <= 9)
    return '0' + n;

  return 'a' + n - 10;
}
