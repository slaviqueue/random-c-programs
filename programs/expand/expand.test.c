#include "expand.h"
#include <criterion/criterion.h>
#include <stdio.h>
#include <string.h>

Test(expand, az) {
  char* s1 = "Here's the alphabet: a-z";
  char s2[64];
  char* expected = "Here's the alphabet: abcdefghijklmnopqrstuvwxyz";

  expand(s1, s2);

  cr_expect_str_eq(s2, expected);
}

Test(expand, abc) {
  char* s1 = "a-b-c";
  char s2[64];
  char* expected = "abc";

  expand(s1, s2);

  cr_expect_str_eq(s2, expected);
}

Test(expand, s1_start_with_hyphen) {
  char* s1 = "-az";
  char s2[8];
  char* expected = "-az";

  expand(s1, s2);

  cr_expect_str_eq(s2, expected);
}

Test(expand, AZ) {
  char* s1 = "Here's the alphabet in uppercase: A-Z";
  char s2[64];
  char* expected =
      "Here's the alphabet in uppercase: ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  expand(s1, s2);

  cr_expect_str_eq(s2, expected);
}

Test(expand, one_to_nine) {
  char* s1 = "1-9";
  char s2[16];
  char* expected = "123456789";

  expand(s1, s2);

  cr_expect_str_eq(s2, expected);
}

Test(expand, combination) {
  char* s1 = "a-z1-9A-Z";
  char s2[64];
  char* expected =
      "abcdefghijklmnopqrstuvwxyz123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  expand(s1, s2);

  cr_expect_str_eq(s2, expected);
}

Test(expand, invalid_combination) {
  char* s1 = "a-0z-aG-40-a";
  char s2[16];
  char* expected = "a-0z-aG-40-a";

  expand(s1, s2);

  cr_expect_str_eq(s2, expected);
}

Test(expand, one_more_invalid_combination) {
  char* s1 = "a--d";
  char s2[16];
  char* expected = "a--d";

  expand(s1, s2);

  cr_expect_str_eq(s2, expected);
}

Test(expand, hyphen_at_the_end) {
  char* s1 = "a-f-";
  char s2[16];
  char* expected = "abcdef-";

  expand(s1, s2);

  cr_expect_str_eq(s2, expected);
}
