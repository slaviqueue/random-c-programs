#include "common.h"
#include <stdio.h>
#include <stdlib.h>

void crash(char* message) {
  fprintf(stderr, "%s\n", message);
  exit(EXIT_FAILURE);
}

int sign(int n) {
  if (n > 0)
    return 1;

  if (n < 0)
    return -1;

  return 0;
}
