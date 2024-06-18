#include "bits.h"
#include <criterion/criterion.h>
#include <sys/types.h>

Test(set_bits, regular_input) {
  uint s1 = 0b11111111;
  uint s2 = 0b00111100;
  uint result = set_bits(s1, 3, 2, s2);

  cr_expect(result == 0b11110011);
}

Test(set_bits, edge_case) {
  uint s1 = 0b11111111;
  uint s2 = 0b00000000;
  uint result = set_bits(s1, 0, 10, s2);

  cr_expect(result == 0b11111111);
}
