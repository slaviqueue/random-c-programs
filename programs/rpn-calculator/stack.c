#include "stack.h"
#include <assert.h>

Stack stack_make() {
  Stack s;
  s._next_free_index = 0;
  return s;
}

void stack_push(Stack* stack, double value) {
  assert(stack->_next_free_index <= STACK_SIZE && "Stack overflow");
  stack->_buffer[stack->_next_free_index++] = value;
}

double stack_pop(Stack* stack) {
  assert((stack->_next_free_index) > 0 && "Cannot pop anymore");
  return stack->_buffer[--stack->_next_free_index];
}

double stack_head(Stack* stack) {
  assert((stack->_next_free_index) >= 0 && "Cannot pop anymore");
  return stack->_buffer[stack->_next_free_index - 1];
}
