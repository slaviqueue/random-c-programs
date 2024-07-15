#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void copystr(FILE* input, FILE* output);
static bool copy_file_to_stdout(char* file_name);

int main(int argc, char* argv[]) {
  bool copying_from_stdin = argc == 1;

  if (copying_from_stdin)
    copystr(stdin, stdout);
  else
    while (--argc > 0)
      if (!copy_file_to_stdout(*++argv))
        return EXIT_FAILURE;

  return EXIT_SUCCESS;
}

static void copystr(FILE* input, FILE* output) {
  char c;

  while ((c = fgetc(input)) != EOF)
    fputc(c, output);
}

static bool copy_file_to_stdout(char* file_name) {
  FILE* input = fopen(file_name, "r");

  if (!input) {
    fprintf(stderr, "Couldn't open the file %s\n", file_name);
    return false;
  }

  copystr(input, stdout);
  fclose(input);
  return true;
}
