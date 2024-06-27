#include <stdio.h>
#include <stdlib.h>
#include "bits.h"

static void print_bits(uint n);

int main() {
  uint get_bits_test_number_input = 0b01010101;
  uint get_bits_test_number_output = bits_get(0b01010101, 2, 3);

  printf("Given a number: \t");
  print_bits(get_bits_test_number_input);
  printf("It's first 3 bits are: \t");
  print_bits(get_bits_test_number_output);

  printf("\n");

  uint set_bits_test_input_s1 = 0b11111111;
  uint set_bits_test_input_s2 = 0b00000000;
  uint set_bits_output =
      bits_set(set_bits_test_input_s1, 5, 3, set_bits_test_input_s2);

  printf("Assign first 3 bits of S2 to bits 5, 4, 3 of S1\n");
  printf("S1:\t");
  print_bits(set_bits_test_input_s1);
  printf("S2:\t");
  print_bits(set_bits_test_input_s2);
  printf("Result:\t");
  print_bits(set_bits_output);

  return EXIT_SUCCESS;
}

void print_bits(uint n) {
  for (int i = sizeof(uint) * 8 - 1; i >= 0; i--)
    printf("%d", n >> i & 1);

  printf("\n");
}
