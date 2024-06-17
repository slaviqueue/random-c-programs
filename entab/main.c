#include <stdio.h>
#include <stdlib.h>

#define SPACES_PER_TAB 2

typedef struct {
  char* input_file_name;
  char* output_file_name;
} Arguments;

static Arguments parse_arguments(int argc, char* argv[]);
static FILE* open_file_safe(char* file, char* mode);
static void entab(FILE* input, FILE* output);

int main(int argc, char* argv[]) {
  Arguments args = parse_arguments(argc, argv);

  FILE* input_file = fopen(args.input_file_name, "r");
  FILE* output_file = fopen(args.output_file_name, "w");

  entab(input_file, output_file);

  fclose(input_file);
  fclose(output_file);
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

static void entab(FILE* input, FILE* output) {
  int current_blanks = 0;
  char current_char;

  while ((current_char = fgetc(input)) != EOF) {
    if (current_char == ' ') {
      if (current_blanks++ == SPACES_PER_TAB) {
        fputc('\t', output);
        current_blanks = 0;
      } else {
        fputc(current_char, output);
        current_blanks++;
      }
    } else {
      fputc(current_char, output);
      current_blanks = 0;
    }
  }
}
