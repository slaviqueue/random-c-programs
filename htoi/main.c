#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void read_hex(char *buffer, int size);
static int htoi(char *hex);

int main(int argc, char *argv[]) {
  while (true) {
    printf("Enter your hex number: ");

    char buffer[BUFSIZ];
    read_hex(buffer, BUFSIZ);

    int result = htoi(buffer);

    if (result == -1)
      printf("Invalid hex number \"%s\", aborting\n", buffer);
    else
      printf("Ten-based value is: %d\n", result);
  }

  return EXIT_SUCCESS;
}

static void read_hex(char *buffer, int size) {
  fgets(buffer, size, stdin);

  // strip new line
  buffer[strlen(buffer) - 1] = 0;
}

static int htoi(char *hex) {
  if (*hex == '0' && hex[1] == 'X' || hex[1] == 'x')
    hex += 2;

  int n = 0;

  for (; *hex != '\0'; hex++) {
    char current_hex_digit = *hex;
    n *= 16;

    if (current_hex_digit >= '0' && current_hex_digit <= '9')
      n += current_hex_digit - '0';
    else if (current_hex_digit >= 'A' && current_hex_digit <= 'F')
      n += 10 + current_hex_digit - 'A';
    else if (current_hex_digit >= 'a' && current_hex_digit <= 'f')
      n += 10 + current_hex_digit - 'a';
    else
      return -1;
  }

  return n;
}
