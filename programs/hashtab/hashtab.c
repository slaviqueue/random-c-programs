#include "hashtab.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static int calculate_hash(char* str, int mod);
static bool append_to_bucket(BucketNode** key_list, char* key, char* value);
static BucketNode* make_bucket_node(char* key, char* value);
static void free_bucket(BucketNode** bucket);

Hashtab hashtab_make() {
  Hashtab tab = {NULL};
  return tab;
}

bool hashtab_set(Hashtab* self, char* key, char* value) {
  int hash = calculate_hash(key, BUCKETS_LEN);
  bool result = append_to_bucket(&self->_buckets[hash], key, value);
  return result;
}

char* hashtab_get(Hashtab* self, char* key) {
  int hash = calculate_hash(key, BUCKETS_LEN);
  BucketNode* node = self->_buckets[hash];

  while (node) {
    if (!strcmp(key, node->_key))
      return node->_value;

    node = node->_next;
  }

  return NULL;
}

static int calculate_hash(char* str, int mod) {
  uint hash = 0;

  while (*str++)
    hash = hash + *str;

  hash %= mod;

  return hash;
}

void hashtab_free(Hashtab* self) {
  for (int i; i < BUCKETS_LEN; i++)
    if (self->_buckets[i])
      free_bucket(&self->_buckets[i]);
}

static bool append_to_bucket(BucketNode** key_list, char* key, char* value) {
  BucketNode* new_node = make_bucket_node(key, value);

  if (!new_node)
    return false;

  if (!*key_list) {
    *key_list = new_node;
    return true;
  }

  BucketNode* node = *key_list;

  while (node->_next)
    node = node->_next;

  node->_next = new_node;
  return true;
}

static BucketNode* make_bucket_node(char* key, char* value) {
  BucketNode* node = malloc(sizeof(BucketNode));

  if (!node)
    return NULL;

  node->_key = key;
  node->_value = value;
  node->_next = NULL;

  return node;
}

static void free_bucket(BucketNode** bucket) {
  BucketNode* node = *bucket;

  while (node) {
    BucketNode* next = node->_next;
    free(node);
    node = next;
  }

  *bucket = NULL;
}
