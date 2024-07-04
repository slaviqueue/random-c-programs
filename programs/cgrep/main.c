#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  bool except;
  bool print_lint_numbers;
  char* pattern;
} Arguments;

static Arguments parse_args(int argc, char** argv);
static void parse_flags(char* arg, Arguments* args);
static bool matches(char* pattern, char* str);

int main(int argc, char* argv[]) {
  Arguments args = parse_args(argc, argv);
  char line[MAX_LINE_LENGTH];
  int line_number = 0;

  while (fgets(line, MAX_LINE_LENGTH, stdin)) {
    ++line_number;

    if (matches(args.pattern, line) == !args.except) {
      if (args.print_lint_numbers)
        printf("%3d ", line_number);

      printf("%s", line);
    }
  }

  return EXIT_SUCCESS;
}

static Arguments parse_args(int argc, char** argv) {
  Arguments parsed_args = {0};

  while (--argc > 0) {
    char* arg = *++argv;

    if (*arg != '-') {
      parsed_args.pattern = arg;
      continue;
    }

    parse_flags(arg, &parsed_args);
  }

  if (!parsed_args.pattern) {
    printf("Usage: cgrep [-e] [-l] pattern\n");
    exit(EXIT_FAILURE);
  }

  return parsed_args;
}

static void parse_flags(char* arg, Arguments* parsed_args) {
  while (*++arg) {
    switch (*arg) {
      case 'x':
        parsed_args->except = true;
        break;
      case 'l':
        parsed_args->print_lint_numbers = true;
        break;
      default:
        printf("Unknown flag: %c\n", *arg);
        exit(EXIT_FAILURE);
        break;
    }
  }
}

static bool matches(char* pattern, char* str) {
  do {
    char* i = str;
    char* j = pattern;

    while (*i++ == *j++)
      ;

    if (!*--j)
      return true;
  } while (*str++);

  return false;
}
