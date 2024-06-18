#include "bits.h"
#include <criterion/criterion.h>
#include <sys/types.h>

Test(bits_set, regular_input) {
  uint s1 = 0b11111111;
  uint s2 = 0b00111100;
  uint result = bits_set(s1, 3, 2, s2);

  cr_expect(result == 0b11110011);
}

Test(bits_set, edge_case) {
  uint s1 = 0b11111111;
  uint s2 = 0b00000000;
  uint result = bits_set(s1, 0, 10, s2);

  cr_expect(result == 0b11111111);
}
