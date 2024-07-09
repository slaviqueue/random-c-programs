#include "linked-list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static struct LinkedListNode* make_node(int value);
static void free_node(struct LinkedListNode* node);

struct LinkedList linked_list_make() {
  struct LinkedList list = {.head = NULL};
  return list;
}

void linked_list_add_last(struct LinkedList* list, int value) {
  struct LinkedListNode* node = make_node(value);

  if (!list->head) {
    list->head = node;
    return;
  }

  struct LinkedListNode* tail = list->head;

  while (tail->next)
    tail = tail->next;

  tail->next = node;
}

void linked_list_add_first(struct LinkedList* list, int value) {
  struct LinkedListNode* head = list->head;
  struct LinkedListNode* new_node = make_node(value);

  new_node->next = head;
  list->head = new_node;
}

int linked_list_pop(struct LinkedList* list, int* result) {
  if (!list->head)
    return -1;

  struct LinkedListNode* head = list->head;
  list->head = head->next;
  *result = head->value;
  free_node(head);

  return 1;
}

void linked_list_remove_by_index(struct LinkedList* list, int index) {
  assert(index >= 0 && "What you expect me to do with a negative index bruh");

  if (!list->head)
    return;

  if (index == 0) {
    struct LinkedListNode* next = list->head->next;
    free_node(list->head);
    list->head = next;
    return;
  }

  struct LinkedListNode* parent = list->head;

  while (parent->next && --index > 0)
    parent = parent->next;

  if (index || !parent->next)
    return;

  struct LinkedListNode* node = parent->next;
  struct LinkedListNode* next = node->next;
  parent->next = next;

  free_node(node);
}

int linked_list_get_by_index(struct LinkedList* list, int index, int* result) {
  assert(index >= 0 && "What you expect me to do with a negative index bruh");

  if (!list->head)
    return -1;

  struct LinkedListNode* node = list->head;

  while (node->next && --index >= 0)
    node = node->next;

  if (index > 0)
    return -1;

  *result = node->value;
  return 1;
}

static struct LinkedListNode* make_node(int value) {
  struct LinkedListNode* node = malloc(sizeof(struct LinkedListNode));
  node->value = value;
  node->next = NULL;

  return node;
}

static void free_node(struct LinkedListNode* node) {
  free(node);
}
