#include <stdio.h>
#include "common.h"

static char _buffer[BUFSIZ];
static int _bufpos = 0;

char io_getch() {
  char val = _bufpos > 0 ? _buffer[_bufpos--] : getc(stdin);
  return val;
}

void io_ungetch(char c) {
  _buffer[++_bufpos] = c;
}
