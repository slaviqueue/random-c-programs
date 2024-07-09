#include "linked-list/linked-list.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <stdio.h>

Test(linked_list_add_last, appends_a_node_to_the_end_of_the_list) {
  struct LinkedList list = linked_list_make();
  linked_list_add_last(&list, 6);
  linked_list_add_last(&list, 9);

  cr_expect_eq(list.head->value, 6);
  cr_expect_eq(list.head->next->value, 9);
}

Test(linked_list_add_first, prepends_a_node_to_the_beginning_of_the_list) {
  struct LinkedList list = linked_list_make();
  linked_list_add_first(&list, 9);
  linked_list_add_first(&list, 6);

  cr_expect_eq(list.head->value, 6);
  cr_expect_eq(list.head->next->value, 9);
}

Test(linked_list_pop, pops_an_element_from_the_list) {
  struct LinkedList list = linked_list_make();
  linked_list_add_last(&list, 6);
  linked_list_add_last(&list, 9);

  int result = 0;
  int popped = linked_list_pop(&list, &result);

  cr_expect_eq(result, 6);
  cr_expect_eq(popped, 1);
  cr_expect_eq(list.head->value, 9);
}

Test(linked_list_pop, returns_minus_one_if_list_is_empty) {
  struct LinkedList list = linked_list_make();

  int result = 0;
  int popped = linked_list_pop(&list, &result);

  cr_expect_eq(popped, -1);
}

Test(linked_list_remove_by_index, removes_an_element_by_index) {
  struct LinkedList list = linked_list_make();
  linked_list_add_last(&list, 6);
  linked_list_remove_by_index(&list, 0);

  cr_expect_eq(list.head, NULL);

  linked_list_add_last(&list, 6);
  linked_list_add_last(&list, 9);
  linked_list_add_last(&list, 6);
  linked_list_remove_by_index(&list, 2);

  cr_expect_eq(list.head->value, 6);
  cr_expect_eq(list.head->next->value, 9);
  cr_expect_eq(list.head->next->next, NULL);
}

Test(linked_list_get_by_index, finds_an_element_by_index) {
  struct LinkedList list = linked_list_make();
  linked_list_add_last(&list, 1);
  linked_list_add_last(&list, 3);
  linked_list_add_last(&list, 3);
  linked_list_add_last(&list, 7);

  int value;
  int found;

  value = 0, found = linked_list_get_by_index(&list, 0, &value);
  cr_expect_eq(value, 1);
  cr_expect_eq(found, 1);

  value = 0, found = linked_list_get_by_index(&list, 1, &value);
  cr_expect_eq(value, 3);
  cr_expect_eq(found, 1);

  value = 0, found = linked_list_get_by_index(&list, 2, &value);
  cr_expect_eq(value, 3);
  cr_expect_eq(found, 1);

  value = 0, found = linked_list_get_by_index(&list, 3, &value);
  cr_expect_eq(value, 7);
  cr_expect_eq(found, 1);
}

Test(linked_list_get_by_index, returns_minus_1_if_not_found) {
  struct LinkedList list = linked_list_make();
  linked_list_add_last(&list, 1);

  int value = 0;
  int found = linked_list_get_by_index(&list, 10, &value);

  cr_expect_eq(value, 0);
  cr_expect_eq(found, -1);
}
