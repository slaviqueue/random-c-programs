#include "binsearch.h"
#include <criterion/criterion.h>
#include <stdio.h>

Test(binsearch, odd_arr) {
  int arr[] = {2, 5, 6, 9, 10};
  int arr_len = sizeof(arr) / sizeof(int);

  int expected_index_of_9 = 3;
  int actual_index_of_9 = binsearch(arr, arr_len, 9);

  cr_expect_eq(actual_index_of_9, expected_index_of_9);
}

Test(binsearch, even_arr) {
  int arr[] = {2, 5, 9, 10};
  int arr_len = sizeof(arr) / sizeof(int);

  int expected_index_of_9 = 2;
  int actual_index_of_9 = binsearch(arr, arr_len, 9);

  cr_expect_eq(expected_index_of_9, actual_index_of_9);
}

Test(binsearch, not_found) {
  int arr[] = {2, 5, 6, 9, 10};
  int arr_len = sizeof(arr) / sizeof(int);

  int expected_index = -1;
  int actual_index = binsearch(arr, arr_len, 1337);

  cr_expect_eq(actual_index, expected_index);
}
