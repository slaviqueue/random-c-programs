#include "cstrcat.h"

void cstrcat(char* s1, char* s2) {
  while (*s1++)
    ;

  while ((*s1++ = *s2++))
    ;
}
