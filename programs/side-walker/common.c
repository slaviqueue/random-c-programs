#include "common.h"
#include <stdio.h>
#include <stdlib.h>

void crash(char* message) {
  fprintf(stderr, "%s\n", message);
  exit(EXIT_FAILURE);
}
