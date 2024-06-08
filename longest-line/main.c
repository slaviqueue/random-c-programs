#include <stdio.h>
#include <string.h>

int main() {
  char buffer[BUFSIZ];

  size_t maxLength = 0;

  while (fgets(buffer, BUFSIZ, stdin) != NULL) {
    size_t currentLength = strlen(buffer);

    if (currentLength > maxLength)
      // write length excluding newline
      maxLength = currentLength - 1;
  }

  printf("The longest line had length of %zu characters\n", maxLength);
}
