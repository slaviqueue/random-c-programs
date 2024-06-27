#include "binsearch.h"
#include <stdio.h>

int binsearch(const int arr[], size_t len, int item) {
  int left = 0;
  int right = len - 1;

  if (left > right)
    return -1;

  while (left <= right) {
    int pivot_index = (left + right) / 2;
    int pivot_value = arr[pivot_index];

    if (item < pivot_value)
      right = pivot_index - 1;
    else if (item > pivot_value)
      left = pivot_index + 1;
    else
      return pivot_index;
  }

  return -1;
}
