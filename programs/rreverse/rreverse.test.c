#include "rreverse/rreverse.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

Test(rreverse, reverses_string_in_place) {
  char str[] = "hello world";
  char expected[] = "dlrow olleh";

  rreverse(str);

  cr_expect_str_eq(str, expected);
}

Test(rreverse, single_character) {
  char str[] = "o";
  char expected[] = "o";

  rreverse(str);

  cr_expect_str_eq(str, expected);
}

Test(rreverse, two_characters) {
  char str[] = "uf";
  char expected[] = "fu";

  rreverse(str);

  cr_expect_str_eq(str, expected);
}

Test(rreverse, empty_string) {
  char str[] = "";
  char expected[] = "";

  rreverse(str);

  cr_expect_str_eq(str, expected);
}
