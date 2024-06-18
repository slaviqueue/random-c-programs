#include "esc.h"

void esc_escape(char* s1, char* s2) {
  for (; *s1 != '\0'; s1++) {
    switch (*s1) {
      case '\t':
        *(s2++) = '\\';
        *(s2++) = 't';
        break;
      case '\n':
        *(s2++) = '\\';
        *(s2++) = 'n';
        break;
      default:
        *(s2++) = *s1;
        break;
    }
  }

  *s2 = '\0';
}

void esc_unescape(char* s1, char* s2) {
  for (; *s1 != '\0'; s1++) {
    if (*s1 != '\\') {
      *(s2++) = *s1;
      continue;
    }

    char next_char = *(++s1);

    switch (next_char) {
      case 'n':
        *(s2++) = '\n';
        break;
      case 't':
        *(s2++) = '\t';
        break;
      default:
        *(s2++) = '\\';
        *(s2++) = next_char;
        break;
    }
  }

  *s2 = '\0';
}
