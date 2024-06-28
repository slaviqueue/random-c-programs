#include "rreverse.h"
#include <stdio.h>
#include <string.h>

static void rreverse_rec(char* str, char* left, char* right);

void rreverse(char* str) {
  int len = strlen(str);
  char* left = str;
  char* right = str + len - 1;

  rreverse_rec(str, left, right);
}

static void rreverse_rec(char* str, char* left, char* right) {
  if (right <= left)
    return;

  char temp = *left;
  *left = *right;
  *right = temp;

  rreverse_rec(str, ++left, --right);
}
