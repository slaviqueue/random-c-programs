#include <stdbool.h>
#include <stdio.h>

static inline bool is_lowercase_letter(char c);
static inline bool is_uppercase_letter(char c);
static inline bool is_number(char c);
static inline int expand_sequence(char from, char to, char* target);

void expand(char* source, char* target) {
  for (int i = 0; source[i] != '\0'; i++) {
    if (source[i] != '-' || i == 0) {
      *(target++) = source[i];
      continue;
    }

    char previous = source[i - 1];
    char next = source[i + 1];

    if (previous >= next ||
        (is_lowercase_letter(previous) != is_lowercase_letter(next)) ||
        (is_uppercase_letter(previous) != is_uppercase_letter(next)) ||
        (is_number(previous) != is_number(next))) {
      *(target++) = source[i];
      continue;
    }

    target--;
    int sequence_length = expand_sequence(previous, next, target);
    target += sequence_length;
  }

  *target = '\0';
}

static inline bool is_lowercase_letter(char c) {
  return c >= 'a' && c <= 'z';
}

static inline bool is_uppercase_letter(char c) {
  return c >= 'A' && c <= 'Z';
}

static inline bool is_number(char c) {
  return c >= '0' && c <= '9';
}

static inline int expand_sequence(char from, char to, char* target) {
  for (char c = from; c < to; c++)
    *(target++) = c;

  int sequence_length = to - from;
  return sequence_length;
}
