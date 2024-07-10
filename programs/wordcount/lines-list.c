#include "lines-list.h"
#include <stdlib.h>

static struct LinesListNode* make_node(int line);

void lines_list_add(struct LinesListNode** parent, int line_number) {
  if (!*parent) {
    *parent = make_node(line_number);
    return;
  }

  struct LinesListNode* node = *parent;

  while (node->next)
    node = node->next;

  node->next = make_node(line_number);
}

void lines_list_for_each(struct LinesListNode** parent, void fn(int line)) {
  while (*parent) {
    fn((*parent)->line_number);
    *parent = (*parent)->next;
  }
}

static struct LinesListNode* make_node(int line_number) {
  struct LinesListNode* node = malloc(sizeof(struct LinesListNode));
  node->line_number = line_number;
  node->next = NULL;

  return node;
}
