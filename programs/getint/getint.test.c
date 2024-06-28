#include "getint/getint.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/redirect.h>

Test(getint, reads_integer_from_stdin) {
  FILE* fake_stdin = cr_get_redirected_stdin();
  fputs("123", fake_stdin);
  fclose(fake_stdin);

  int num;
  GetIntStatus status = getint(&num);

  cr_expect_eq(status, GetIntStatusNumberFound);
  cr_expect_eq(num, 123);
}

Test(getint, reads_negative_integers) {
  FILE* fake_stdin = cr_get_redirected_stdin();
  fputs("-123", fake_stdin);
  fclose(fake_stdin);

  int num;
  GetIntStatus status = getint(&num);

  cr_expect_eq(status, GetIntStatusNumberFound);
  cr_expect_eq(num, -123);
}

Test(getint, reads_explicitly_positive_integers) {
  FILE* fake_stdin = cr_get_redirected_stdin();
  fputs("+123", fake_stdin);
  fclose(fake_stdin);

  int num;
  GetIntStatus status = getint(&num);

  cr_expect_eq(status, GetIntStatusNumberFound);
  cr_expect_eq(num, 123);
}

Test(getint, reads_zero) {
  FILE* fake_stdin = cr_get_redirected_stdin();
  fputs("0", fake_stdin);
  fclose(fake_stdin);

  int num;
  GetIntStatus status = getint(&num);

  cr_expect_eq(status, GetIntStatusNumberFound);
  cr_expect_eq(num, 0);
}

Test(getint, returns_not_a_number_if_theres_not_a_number) {
  FILE* fake_stdin = cr_get_redirected_stdin();
  fputs("I just wanna tell you how I'm feeling", fake_stdin);
  fclose(fake_stdin);

  int num;
  GetIntStatus status = getint(&num);

  cr_expect_eq(status, GetIntStatusNotANumber);
  cr_expect_eq(getc(stdin), 'I');
}
