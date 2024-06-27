#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *s1;
  char *s2;
} Arguments;

static Arguments parse_arguments(int argc, char *argv[]);
static int any(const char *s1, const char *s2);

int main(int argc, char *argv[]) {
  Arguments args = parse_arguments(argc, argv);

  int location = any(args.s1, args.s2);
  printf("Found character from <s2> at position %d\n", location + 1);

  return EXIT_SUCCESS;
}

static Arguments parse_arguments(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <s1> <s2>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  return (Arguments){
      .s1 = argv[1],
      .s2 = argv[2],
  };
}

static int any(const char *s1, const char *s2) {
  for (int i = 0; s1[i] != '\0'; i++)
    for (int j = 0; s2[j] != '\0'; j++)
      if (s1[i] == s2[j])
        return i;

  return -1;
}

