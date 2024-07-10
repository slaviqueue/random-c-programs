#pragma once

struct WordsBinaryTreeNode {
  char* word;
  int count;
  int compare_first_n_characters;
  struct WordsBinaryTreeNode* left;
  struct WordsBinaryTreeNode* right;
};

struct WordsBinaryTree {
  struct WordsBinaryTreeNode* root;
};

struct WordsBinaryTree words_binary_tree_make();
void words_binary_tree_push_word(struct WordsBinaryTree* tree, char* word);
void words_binary_tree_for_each_node(struct WordsBinaryTree* tree,
                                     void fn(struct WordsBinaryTreeNode*));
