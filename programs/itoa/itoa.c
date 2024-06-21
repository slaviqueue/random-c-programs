#include <string.h>

static inline char* reverse(char* s1);

char* itoa(int n, char* s, int width) {
  char* s_start = s;
  int sign = n;

  if (sign < 0)
    n *= -1;

  do {
    *(s++) = '0' + n % 10;
    width--;
  } while ((n /= 10) > 0);

  if (sign < 0) {
    *(s++) = '-';
    width--;
  }

  for (; width > 0; *(s++) = ' ', width--)
    ;

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
