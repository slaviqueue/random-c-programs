#include <stdio.h>
#include "common.h"

static char buffer[BUFSIZ];
static int bufpos = 0;

char io_getch() {
  char val = bufpos > 0 ? buffer[bufpos--] : getc(stdin);
  return val;
}

void io_ungetch(char c) {
  buffer[++bufpos] = c;
}
