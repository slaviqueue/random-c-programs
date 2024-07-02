#include "strend.h"
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>

bool strend(char* s1, char* s2) {
  ulong s1_len = strlen(s1);
  ulong s2_len = strlen(s2);

  if (s1_len < s2_len)
    return false;

  ulong len_diff = s1_len - s2_len;
  bool is_s2_a_substr_of_s1 = strcmp(s1 + len_diff, s2) == 0;
  return is_s2_a_substr_of_s1;
}
