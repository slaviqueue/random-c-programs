#include "strindexr.h"
#include <criterion/criterion.h>

Test(expand, found) {
  int i = strindexr("somebody once told me the world is gonna roll me", "me");
  cr_expect_eq(i, 46);
}

Test(expand, not_found) {
  int i = strindexr("I ain't the sharpest tool in the shed", "yay");
  cr_expect_eq(i, -1);
}
