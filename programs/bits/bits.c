#include "bits.h"
#include <stdio.h>

static void print_bits(uint n) {
  for (int i = sizeof(uint) * 8 - 1; i >= 0; i--)
    printf("%d", n >> i & 1);

  printf("\n");
}

uint get_bits(uint source, int position, int numbits) {
  return (source >> (position + 1 - numbits)) & ~(~0 << numbits);
}

uint set_bits(uint source, int position, int numbits, uint y) {
  int offset = position + 1 - numbits;
  uint bits_to_set = (y & ~(~0 << numbits)) << offset;
  uint source_mask = ~(~(~0 << numbits) << offset);
  uint masked_source = source & source_mask;

  return masked_source | bits_to_set;
}
