#include "swapm.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(swapm, swap_two_variables) {
  int a = 2;
  int b = 3;

  SWAPM(int, &a, &b);

  cr_expect_eq(a, 3);
  cr_expect_eq(b, 2);
}
