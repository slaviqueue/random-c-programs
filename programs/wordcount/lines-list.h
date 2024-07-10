#pragma once

// Important: always initialize empty lists with NULL, like this:
// struct LinesListNode* list = NULL;

struct LinesListNode {
  struct LinesListNode* next;
  int line_number;
};

void lines_list_add(struct LinesListNode** parent, int line_number);
void lines_list_for_each(struct LinesListNode** parent,
                         void fn(int line_number));
