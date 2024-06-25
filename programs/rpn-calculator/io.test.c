#include "io.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "common.h"
Test(io_getch_ungetch, getch_ungetch) {
  FILE* fake_stdin = cr_get_redirected_stdin();
  fputc('c', fake_stdin);

  cr_expect_eq(io_getch(), 'c');

  io_ungetch('s');
  io_ungetch('b');

  cr_expect_eq(io_getch(), 'b');
  cr_expect_eq(io_getch(), 's');

  fclose(fake_stdin);
}
