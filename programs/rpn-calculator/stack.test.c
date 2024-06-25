#include "stack.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <stdio.h>

Test(stack, push_pop) {
  Stack stack = stack_make();

  stack_push(&stack, 37);
  stack_push(&stack, 13);

  cr_expect_eq(stack_pop(&stack), 13);
  cr_expect_eq(stack_pop(&stack), 37);
}
