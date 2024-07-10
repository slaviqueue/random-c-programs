#include "wordcount/getword.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>

#define MAX_WORD_LEN 128

Test(getword, gets_word) {
  FILE* fake_stdin = cr_get_redirected_stdin();
  fputs("   hey there", fake_stdin);
  fclose(fake_stdin);

  char buf[MAX_WORD_LEN] = {0};
  char* first_char = NULL;

  first_char = getword(buf, MAX_WORD_LEN);
  cr_expect_str_eq(buf, "hey");
  cr_expect_eq(first_char, buf);

  first_char = getword(buf, MAX_WORD_LEN);
  cr_expect_str_eq(buf, "there");
  cr_expect_eq(first_char, buf);

  first_char = getword(buf, MAX_WORD_LEN);
  cr_expect_eq(first_char, NULL);
}
