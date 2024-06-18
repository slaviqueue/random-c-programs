#include "bits.h"
#include <stdio.h>

uint bits_get(uint source, int position, int numbits) {
  return (source >> (position + 1 - numbits)) & ~(~0 << numbits);
}

uint bits_set(uint source, int position, int numbits, uint y) {
  int offset = position + 1 - numbits;
  uint bits_to_set = (y & ~(~0 << numbits)) << offset;
  uint source_mask = ~(~(~0 << numbits) << offset);
  uint masked_source = source & source_mask;

  return masked_source | bits_to_set;
}
