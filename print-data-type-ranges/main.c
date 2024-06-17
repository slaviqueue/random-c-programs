#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  printf(
      "Yo, here are some data type ranges according to what we've found in "
      "<limits.h>:\n");

  printf("Signed char: min = %d, max = %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("Unsigned char: min = 0, max = %d\n", UCHAR_MAX);
  printf("Short int: min = %d, max = %d\n", SHRT_MIN, SHRT_MAX);
  printf("Unsigned short int: min = 0, max = %d\n", USHRT_MAX);
  printf("Regular int: min = %d, max = %d\n", INT_MIN, INT_MAX);
  printf("Unsigned int: min = 0, max = %ud\n", UINT_MAX);
  printf("Long int: min = %ld, max = %ld\n", LONG_MIN, LONG_MAX);
  printf("Unsigned long int: min = 0, max = %lu\n", ULONG_MAX);

  return EXIT_SUCCESS;
}
