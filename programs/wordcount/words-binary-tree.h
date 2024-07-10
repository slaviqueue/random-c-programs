#pragma once

#include "wordcount/lines-list.h"
struct WordsBinaryTreeNode {
  struct LinesListNode* lines;
  struct WordsBinaryTreeNode* left;
  struct WordsBinaryTreeNode* right;
  char* word;
  int count;
  int compare_first_n_characters;
};

struct WordsBinaryTree {
  struct WordsBinaryTreeNode* root;
};

struct WordsBinaryTree words_binary_tree_make();
void words_binary_tree_push_word(struct WordsBinaryTree* tree,
                                 char* word,
                                 int line_number);
void words_binary_tree_for_each_node(struct WordsBinaryTree* tree,
                                     void fn(struct WordsBinaryTreeNode*));
