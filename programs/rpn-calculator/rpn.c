#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "getop.h"
#include "stack.h"

static void print_help(void);

void rpn_eval() {
  Stack stack = stack_make();

  TokenType token_type;
  char token_value[BUFSIZ];

  printf("> ");
  while ((token_type = getop(token_value)) != TOKEN_EOF) {
    switch (token_type) {
      case TOKEN_NEWLINE: {
        printf("> ");
        break;
      }
      case TOKEN_NUMBER: {
        stack_push(&stack, atof(token_value));
        break;
      }
      case TOKEN_OPERATION: {
        if (!strcmp(token_value, "+") || !strcmp(token_value, "add")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, op1 + op2);
          break;
        }

        if (!strcmp(token_value, "-") || !strcmp(token_value, "sub")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, op1 - op2);
          break;
        }

        if (!strcmp(token_value, "*") || !strcmp(token_value, "mul")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, op1 * op2);
          break;
        }

        if (!strcmp(token_value, "/") || !strcmp(token_value, "div")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, op1 * op2);
          break;
        }

        if (!strcmp(token_value, "%") || !strcmp(token_value, "mod")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, (int)op1 % (int)op2);
          break;
        }

        if (!strcmp(token_value, "sin")) {
          stack_push(&stack, sin(stack_pop(&stack)));
          break;
        }

        if (!strcmp(token_value, "cos")) {
          stack_push(&stack, sin(stack_pop(&stack)));
          break;
        }

        if (!strcmp(token_value, "tan")) {
          stack_push(&stack, sin(stack_pop(&stack)));
          break;
        }

        if (!strcmp(token_value, "print")) {
          printf("%f\n", stack_pop(&stack));
          break;
        }

        if (!strcmp(token_value, "help")) {
          print_help();
          break;
        }

        if (!strcmp(token_value, "quit") || !strcmp(token_value, "q")) {
          exit(EXIT_SUCCESS);
          break;
        }

        printf("Unknown operation %s\n", token_value);
        exit(EXIT_FAILURE);
        break;
      }

      case TOKEN_EOF:
        break;

      case TOKEN_UNKNOWN:
      default: {
        printf("Unknown token %s\n", token_value);
        exit(EXIT_FAILURE);
        break;
      }
    }
  }
}

static void print_help(void) {
  printf(
      "rpn calculator repl\n"
      "Operations:\n"
      "\thelp - Print this help message\n"
      "\tadd (+) - Add two numbers\n"
      "\tsub (-)  - Subtract two numbers\n"
      "\tmul (*) - Multiply two numbers\n"
      "\tdiv (/) - Divide two numbers\n"
      "\tmod (%%) - Get remainder\n"
      "\tsin - Get sin of a number\n"
      "\tquit (q, exit) - Exit\n"
      "\tprint - Print last number from the stack\n");
}
