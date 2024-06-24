#include "atofs.h"
#include <criterion/criterion.h>
#include <float.h>

Test(atof, integer) {
  cr_expect_eq(2.0, atofs("2"));
}

Test(atof, pad_left) {
  cr_expect_eq(2, atofs("  \t  2"));
}

Test(atof, floating_point) {
  cr_expect_eq(2.2, atofs("2.2"));
}

Test(atof, negative_floating_point) {
  cr_expect_float_eq(-2.2, atofs("-2.2"), 0.01);
}

Test(atof, scientific_notation) {
  cr_expect_float_eq(133.7, atofs("1.337e2"), 0.001);
  cr_expect_float_eq(13.37, atofs("1337e-2"), 0.001);
  cr_expect_float_eq(133700, atofs("1337e+2"), 0.001);
}

Test(atof, combination) {
  cr_expect_float_eq(-23943.94, atofs("    \t\t\t  \t\t -0.2394394e5"), 0.001);
}
