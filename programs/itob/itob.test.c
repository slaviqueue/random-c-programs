#include "itob.h"
#include <criterion/criterion.h>

Test(expand, decimal) {
  char s2[16];
  itob(12, s2, 10);

  cr_expect_str_eq(s2, "12");
}

Test(expand, decimal_zero) {
  char s2[16];
  itob(0, s2, 10);

  cr_expect_str_eq(s2, "0");
}

Test(expand, binary) {
  char s2[16];
  itob(8, s2, 2);

  cr_expect_str_eq(s2, "1000");
}

Test(expand, octal) {
  char s2[16];
  itob(64, s2, 8);

  cr_expect_str_eq(s2, "100");
}

Test(expand, hex) {
  char s2[16];
  itob(48879, s2, 16);

  cr_expect_str_eq(s2, "beef");
}

Test(expand, negative_hex) {
  char s2[16];
  itob(-48879, s2, 16);

  cr_expect_str_eq(s2, "-beef");
}
