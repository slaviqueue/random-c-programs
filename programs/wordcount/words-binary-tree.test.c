#include "wordcount/words-binary-tree.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(words_binary_tree, a_binary_tree_containing_words_and_their_counters) {
  struct WordsBinaryTree tree = words_binary_tree_make();
  words_binary_tree_push_word(&tree, "ddd");
  words_binary_tree_push_word(&tree, "bbb");
  words_binary_tree_push_word(&tree, "aaa");
  words_binary_tree_push_word(&tree, "ggg");
  words_binary_tree_push_word(&tree, "hhh");
  words_binary_tree_push_word(&tree, "aaa");
  words_binary_tree_push_word(&tree, "aaa");
  words_binary_tree_push_word(&tree, "aaa");

  cr_expect_str_eq(tree.root->word, "ddd");
  cr_expect_str_eq(tree.root->left->word, "bbb");
  cr_expect_str_eq(tree.root->left->left->word, "aaa");
  cr_expect_eq(tree.root->left->left->count, 4);
  cr_expect_str_eq(tree.root->right->word, "ggg");
  cr_expect_str_eq(tree.root->right->right->word, "hhh");
}
