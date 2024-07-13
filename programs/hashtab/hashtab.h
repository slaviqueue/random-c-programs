#pragma once

#define BUCKETS_LEN 64

typedef struct BucketNode {
  struct BucketNode* _next;
  char* _key;
  char* _value;
} BucketNode;

typedef struct {
  BucketNode* _buckets[BUCKETS_LEN];
} Hashtab;

Hashtab hashtab_make();
void hashtab_set(Hashtab* self, char* key, char* value);
char* hashtab_get(Hashtab* self, char* key);
void hashtab_free(Hashtab* self);
