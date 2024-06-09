#include <stdio.h>
#include <string.h>

int main() {
  char longest_line[BUFSIZ];
  size_t max_length = 0;

  char buffer[BUFSIZ];

  while (fgets(buffer, BUFSIZ, stdin) != NULL) {
    size_t current_length = strlen(buffer);

    if (current_length > max_length) {
      max_length = current_length;
      strcpy(longest_line, buffer);
    }
  }

  printf("The longest line had length of %zu characters, it's contents is:\n",
         max_length);
  printf("%s", longest_line);
}
