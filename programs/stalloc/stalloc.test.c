#include "stalloc/stalloc.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(stalloc_stfree, allocates_n_bytes_in_internal_array) {
  char* pt1 = stalloc(8);

  char* pt2 = stalloc(16);
  char* pt3 = stalloc(16);
  stfree(pt3);
  stfree(pt2);

  char* pt22 = stalloc(16);

  cr_expect_gt(pt2, pt1);
  cr_expect_gt(pt3, pt2);
  cr_expect_gt(pt22, pt1);

  cr_expect_eq(pt2, pt22);
}
