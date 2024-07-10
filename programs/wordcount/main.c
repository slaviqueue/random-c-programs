#include <stdio.h>
#include <stdlib.h>
#include "wordcount/getword.h"
#include "wordcount/words-binary-tree.h"

#define MAX_WORD_LEN 128

static void print_node(struct WordsBinaryTreeNode* node) {
  printf("%s: %d\n", node->word, node->count);
}

int main() {
  struct WordsBinaryTree tree = words_binary_tree_make();
  char buf[MAX_WORD_LEN] = {0};

  while (getword(buf, MAX_WORD_LEN))
    words_binary_tree_push_word(&tree, buf);

  words_binary_tree_for_each_node(&tree, print_node);

  return EXIT_SUCCESS;
}
