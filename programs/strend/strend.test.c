#include "strend.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(strend, check_if_s2_is_in_the_end_of_s1) {
  char* s1 = "I got the Rollie on my arm and I'm pouring Chandon";
  char* s2 = "Chandon";

  cr_expect_eq(strend(s1, s2), true);
}

Test(strend, return_false) {
  char* s1 = "Drop it like it's hot";
  char* s2 = "Chandon";

  cr_expect_eq(strend(s1, s2), false);
}
