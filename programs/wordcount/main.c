#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordcount/getword.h"
#include "wordcount/lines-list.h"
#include "wordcount/words-binary-tree.h"

#define MAX_WORD_LEN 128

struct Arguments {
  int exclude_words_smaller_than;
};

static void print_node(struct WordsBinaryTreeNode* node);
static struct Arguments parse_args(int argc, char** argv);

int main(int argc, char** argv) {
  struct Arguments args = parse_args(argc, argv);

  struct WordsBinaryTree tree = words_binary_tree_make();
  char buf[MAX_WORD_LEN] = {0};
  int line_number = 1;

  while (getword(buf, MAX_WORD_LEN, &line_number))
    if (!args.exclude_words_smaller_than ||
        strlen(buf) >= args.exclude_words_smaller_than)
      words_binary_tree_push_word(&tree, buf, line_number);

  words_binary_tree_for_each_node(&tree, print_node);

  return EXIT_SUCCESS;
}

static void print_node(struct WordsBinaryTreeNode* node) {
  printf("\"%.10s\" \t%d times \t", node->word, node->count);

  for (struct LinesListNode* line = node->lines; line; line = line->next)
    printf(line->next ? "%d " : "%d", line->line_number);

  printf("\n");
}

static struct Arguments parse_args(int argc, char** argv) {
  char* program = *argv;
  struct Arguments args = {0};

  while (--argc) {
    char* arg = *++argv;

    if (*arg != '-')
      continue;

    if (*++arg == 'x' && argc > 1) {
      argc--;
      args.exclude_words_smaller_than = atoi(*++argv);

      if (args.exclude_words_smaller_than < 0)
        goto failure;

      continue;
    }

  failure:
    fprintf(stderr, "Usage: %s [-x N]\n", program);
    exit(EXIT_FAILURE);
  }

  return args;
}
