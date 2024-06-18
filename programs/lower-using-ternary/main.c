#include <stdio.h>
#include <stdlib.h>

#define LOWER_OFFSET ('a' - 'A')

static void lower(char* s);

int main(int argc, char* argv[]) {
  char buffer[BUFSIZ];
  fgets(buffer, BUFSIZ, stdin);

  lower(buffer);
  printf("%s", buffer);

  return EXIT_SUCCESS;
}

// personally, I find this code disgusting
static void lower(char* s) {
  for (; *s != '\0'; s++)
    *s = *s >= 'A' && *s <= 'Z' ? *s + LOWER_OFFSET : *s;
}
