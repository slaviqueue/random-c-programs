#include <stdio.h>
#include <stdlib.h>

#define SPACES_PER_TAB 2

typedef struct {
  char* input_file_name;
  char* output_file_name;
} Arguments;

static Arguments parse_arguments(int argc, char* argv[]);
static FILE* open_file_safe(char* file, char* mode);
static void detab(FILE* input, FILE* output);

int main(int argc, char* argv[]) {
  Arguments args = parse_arguments(argc, argv);

  FILE* input = open_file_safe(args.input_file_name, "r");
  FILE* output = open_file_safe(args.output_file_name, "w");

  detab(input, output);

  fclose(input);
  fclose(output);

  return EXIT_SUCCESS;
}

static Arguments parse_arguments(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Usage: %s <input_file> <output_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  return (Arguments){
      .input_file_name = argv[1],
      .output_file_name = argv[2],
  };
}

static FILE* open_file_safe(char* name, char* mode) {
  FILE* file = fopen(name, mode);

  if (file == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  return file;
}

static void detab(FILE* input, FILE* output) {
  char current;

  while ((current = fgetc(input)) != EOF)
    if (current == '\t')
      fputs(" ", output);
    else
      fputc(current, output);
}
