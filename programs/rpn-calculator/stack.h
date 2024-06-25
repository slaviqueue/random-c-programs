#pragma once

#define STACK_SIZE 256

typedef struct Stack {
  double _buffer[STACK_SIZE];
  int _next_free_index;
} Stack;

Stack stack_make();
void stack_push(Stack* stack, double value);
double stack_pop(Stack* stack);
