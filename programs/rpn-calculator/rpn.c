#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "lexer.h"
#include "stack.h"

static void print_help(void);
static bool is_operation(Token token, char* operation_name);

void rpn_eval() {
  Stack stack = stack_make();
  Lexer lexer = lexer_make();
  Token token;

  printf("> ");
  while ((token = lexer_next_token(&lexer)).type != TOKEN_EOF) {
    switch (token.type) {
      case TOKEN_NEWLINE: {
        printf("> ");
        break;
      }
      case TOKEN_NUMBER: {
        stack_push(&stack, atof(token.value));
        break;
      }
      case TOKEN_OPERATION: {
        if (is_operation(token, "+") || is_operation(token, "add")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, op1 + op2);
          break;
        }

        if (is_operation(token, "-") || is_operation(token, "sub")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, op1 - op2);
          break;
        }

        if (is_operation(token, "*") || is_operation(token, "mul")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, op1 * op2);
          break;
        }

        if (is_operation(token, "/") || is_operation(token, "div")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, op1 / op2);
          break;
        }

        if (is_operation(token, "%") || is_operation(token, "mod")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, (int)op1 % (int)op2);
          break;
        }

        if (is_operation(token, "sin")) {
          stack_push(&stack, sin(stack_pop(&stack)));
          break;
        }

        if (is_operation(token, "cos")) {
          stack_push(&stack, sin(stack_pop(&stack)));
          break;
        }

        if (is_operation(token, "tan")) {
          stack_push(&stack, sin(stack_pop(&stack)));
          break;
        }

        if (is_operation(token, "print")) {
          printf("%f\n", stack_head(&stack));
          break;
        }

        if (is_operation(token, "help")) {
          print_help();
          break;
        }

        if (is_operation(token, "quit") || is_operation(token, "q") ||
            is_operation(token, "exit")) {
          printf("Bye!\n");
          exit(EXIT_SUCCESS);
          break;
        }

        printf("Unknown operation %s\n", token.value);
        exit(EXIT_FAILURE);
        break;
      }

      case TOKEN_EOF:
        break;

      case TOKEN_UNKNOWN:
      default: {
        printf("Unknown token %s\n", token.value);
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
      "  help - Print this help message\n"
      "  add (+) - Add two numbers\n"
      "  sub (-)  - Subtract two numbers\n"
      "  mul (*) - Multiply two numbers\n"
      "  div (/) - Divide two numbers\n"
      "  mod (%%) - Get remainder\n"
      "  sin - Get sin of a number\n"
      "  quit (q, exit) - Exit\n"
      "  print - Print last number from the stack\n");
}

static bool is_operation(Token token, char* operation_name) {
  return !strcmp(token.value, operation_name);
}
