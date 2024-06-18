#include "esc.h"
#include <criterion/criterion.h>
#include <stdio.h>
#include <string.h>

Test(esc_escape, changes_made) {
  char* s1 = "Hello,\t my name is\n Slim\nShady";
  char s2[128];

  esc_escape(s1, s2);

  cr_assert_str_eq(s2, "Hello,\\t my name is\\n Slim\\nShady");
}

Test(esc_escape, no_changes_made) {
  char* s1 = "His palms are sweaty, \\tknees weak, arms are heavy";
  char s2[128];

  esc_escape(s1, s2);

  cr_assert_str_eq(s1, s2);
}

Test(esc_unescape, changes_made) {
  char* s1 = "There's\\tvomit on his\\nsweater already,\\nmom's spaghetti";
  char s2[128];

  esc_unescape(s1, s2);

  cr_assert_str_eq(s2,
                   "There's\tvomit on his\nsweater already,\nmom's spaghetti");
}

Test(esc_unescape, no_changes_made) {
  char* s1 = "He's nervous, \tbut on \nthe surface, he looks calm and ready";
  char s2[128];

  esc_unescape(s1, s2);

  cr_assert_str_eq(s1, s2);
}
