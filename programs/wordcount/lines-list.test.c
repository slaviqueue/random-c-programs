#include "wordcount/lines-list.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <stdio.h>

Test(lines_list, just_a_linked_list_with_ints) {
  struct LinesListNode* lines_list = NULL;

  lines_list_add(&lines_list, 13);
  lines_list_add(&lines_list, 37);
  lines_list_add(&lines_list, 2);
  lines_list_add(&lines_list, 88);

  cr_expect_eq(lines_list->line_number, 13);
  cr_expect_eq(lines_list->next->line_number, 37);
  cr_expect_eq(lines_list->next->next->line_number, 2);
  cr_expect_eq(lines_list->next->next->next->line_number, 88);
  cr_expect_eq(lines_list->next->next->next->next, NULL);
}
