#include "words-binary-tree.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct WordsBinaryTreeNode* make_node(char* word);
static struct WordsBinaryTreeNode* push_to_node(
    struct WordsBinaryTreeNode* node,
    char* word);
static void for_each_node(struct WordsBinaryTreeNode* node,
                          void fn(struct WordsBinaryTreeNode*));
static char* copy_word(char* word);
static void malloc_crash();

struct WordsBinaryTree words_binary_tree_make() {
  struct WordsBinaryTree tree = {NULL};

  return tree;
}

void words_binary_tree_push_word(struct WordsBinaryTree* tree, char* word) {
  tree->root = push_to_node(tree->root, word);
}

static struct WordsBinaryTreeNode* make_node(char* word) {
  struct WordsBinaryTreeNode* node = malloc(sizeof(struct WordsBinaryTreeNode));

  if (node == NULL)
    malloc_crash();

  node->word = copy_word(word);
  node->count = 1;
  node->left = NULL;
  node->right = NULL;

  return node;
}

static struct WordsBinaryTreeNode* push_to_node(
    struct WordsBinaryTreeNode* node,
    char* word) {
  if (node == NULL)
    return make_node(word);

  int comparison = strcmp(word, node->word);

  if (comparison == 0)
    node->count++;
  else if (comparison < 0)
    node->left = push_to_node(node->left, word);
  else
    node->right = push_to_node(node->right, word);

  return node;
}

void words_binary_tree_for_each_node(struct WordsBinaryTree* tree,
                                     void fn(struct WordsBinaryTreeNode*)) {
  for_each_node(tree->root, fn);
}

static void for_each_node(struct WordsBinaryTreeNode* node,
                          void fn(struct WordsBinaryTreeNode* node)) {
  if (node == NULL)
    return;

  for_each_node(node->left, fn);
  fn(node);
  for_each_node(node->right, fn);
}

static char* copy_word(char* word) {
  size_t len = strlen(word);
  char* copy = malloc(sizeof(char) * len + 1);

  memcpy(copy, word, len);
  copy[len] = '\0';

  return copy;
}

static void malloc_crash() {
  fprintf(stderr, "Couldn't allocate");
  exit(EXIT_FAILURE);
}
