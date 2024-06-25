#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "io.h"
#include "stack.h"
#include "token.h"

int main(int argc, char* argv[]) {
  char buf[256];
  TokenType token_type;

  while ((token_type = token_read_to(buf)) != TOKEN_EOF &&
         token_type != TOKEN_UNKNOWN) {
    LOGV(token_type, "d");
    LOGV(buf, "s");
    LOGN();
  }

  return EXIT_SUCCESS;
}
