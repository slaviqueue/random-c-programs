#include "itoa.h"
#include <criterion/criterion.h>

Test(expand, no_padding) {
  char s2[16];
  itoa(1337, s2, 4);

  cr_expect_str_eq(s2, "1337");
}

Test(expand, decimal) {
  char s2[16];
  itoa(1337, s2, 10);

  cr_expect_str_eq(s2, "      1337");
}

Test(expand, invalid_min_width) {
  char s2[16];
  itoa(1337, s2, 2);

  cr_expect_str_eq(s2, "1337");
}

Test(expand, negative) {
  char s2[16];
  itoa(-1337, s2, 6);

  cr_expect_str_eq(s2, " -1337");
}
