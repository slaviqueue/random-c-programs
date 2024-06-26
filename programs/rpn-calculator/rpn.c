#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "lexer.h"
#include "stack.h"

static void print_help(void);

void rpn_eval() {
  Stack stack = stack_make();

  Token token;
  Lexer lexer = lexer_make();

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
        if (!strcmp(token.value, "+") || !strcmp(token.value, "add")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, op1 + op2);
          break;
        }

        if (!strcmp(token.value, "-") || !strcmp(token.value, "sub")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, op1 - op2);
          break;
        }

        if (!strcmp(token.value, "*") || !strcmp(token.value, "mul")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, op1 * op2);
          break;
        }

        if (!strcmp(token.value, "/") || !strcmp(token.value, "div")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, op1 * op2);
          break;
        }

        if (!strcmp(token.value, "%") || !strcmp(token.value, "mod")) {
          double op1 = stack_pop(&stack);
          double op2 = stack_pop(&stack);
          stack_push(&stack, (int)op1 % (int)op2);
          break;
        }

        if (!strcmp(token.value, "sin")) {
          stack_push(&stack, sin(stack_pop(&stack)));
          break;
        }

        if (!strcmp(token.value, "cos")) {
          stack_push(&stack, sin(stack_pop(&stack)));
          break;
        }

        if (!strcmp(token.value, "tan")) {
          stack_push(&stack, sin(stack_pop(&stack)));
          break;
        }

        if (!strcmp(token.value, "print")) {
          printf("%f\n", stack_pop(&stack));
          break;
        }

        if (!strcmp(token.value, "help")) {
          print_help();
          break;
        }

        if (!strcmp(token.value, "quit") || !strcmp(token.value, "q") ||
            !strcmp(token.value, "exit")) {
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
