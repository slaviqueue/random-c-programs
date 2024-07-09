#pragma once

struct LinkedListNode {
  int value;
  struct LinkedListNode* next;
};

struct LinkedList {
  struct LinkedListNode* head;
};

struct LinkedList linked_list_make();
void linked_list_add_last(struct LinkedList* list, int value);
void linked_list_add_first(struct LinkedList* list, int value);
int linked_list_pop(struct LinkedList* list, int* result);
void linked_list_remove_by_index(struct LinkedList* list, int index);
int linked_list_get_by_index(struct LinkedList* list, int index, int* result);
