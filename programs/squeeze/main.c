#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char* s1;
  char* s2;
} Arguments;

static Arguments parse_arguments(int argc, char* argv[]);
static void squeeze(char* s1, char* s2);

int main(int argc, char* argv[]) {
  Arguments args = parse_arguments(argc, argv);

  squeeze(args.s1, args.s2);
  printf("%s\n", args.s1);

  return EXIT_SUCCESS;
}

static Arguments parse_arguments(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Usage: %s <s1> <s2>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  return (Arguments){
      .s1 = argv[1],
      .s2 = argv[2],
  };
}

static void squeeze(char* s1, char* s2) {
  int i = 0, j = 0;

  for (; s1[i] != '\0'; i++) {
    bool found = false;

    for (int k = 0; s2[k] != '\0'; k++) {
      if (s1[i] == s2[k]) {
        found = true;
        break;
      }
    }

    if (!found)
      s1[j++] = s1[i];
  }

  s1[j] = '\0';
}
