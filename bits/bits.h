#pragma once

#include <sys/types.h>

// Returns the (right adjusted) n-bit field of x that begins at position p
uint get_bits(uint source, int p, int n);

// Returns x with the n bits that begin at position p set to the rightmost n
// bits of y, leaving the other bits unchanged
uint set_bits(uint source, int p, int n, uint y);
