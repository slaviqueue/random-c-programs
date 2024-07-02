#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(strcat, concatenate_two_strings) {
  char s1[64] = "Drop it like it's hot\n";
  char s2[] = "Drop it like it's hot\n";

  strcat(s1, s2);

  cr_expect_str_eq(s1, "Drop it like it's hot\nDrop it like it's hot\n");
}
