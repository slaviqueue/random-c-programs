#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void copystr(FILE* input, FILE* output);
static bool copy_file_to_stdout(char* program_name, char* file_name);

int main(int argc, char* argv[]) {
  char* program_name = *argv;
  bool copying_from_stdin = argc == 1;

  if (copying_from_stdin)
    copystr(stdin, stdout);
  else
    while (--argc > 0)
      if (!copy_file_to_stdout(program_name, *++argv))
        return EXIT_FAILURE;

  if (ferror(stdout)) {
    fprintf(stderr, "%s: Couldn't write to stdout\n", program_name);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

static void copystr(FILE* input, FILE* output) {
  char c;

  while ((c = fgetc(input)) != EOF)
    fputc(c, output);
}

static bool copy_file_to_stdout(char* program_name, char* file_name) {
  FILE* input = fopen(file_name, "r");

  if (!input) {
    fprintf(stderr, "%s: Couldn't open the file %s\n", program_name, file_name);
    return false;
  }

  copystr(input, stdout);
  fclose(input);
  return true;
}
