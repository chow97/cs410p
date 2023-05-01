/*
The init_stack() function initializes a stack with the given size.

The push() function pushes the given value onto the stack.

The pop() function pops the top element off the stack and returns its value.

The free_stack() function frees the memory allocated for the stack.
*/
#include <stdio.h>
#include <stdlib.h>

struct stack {
  void **data;
  size_t size;
  size_t top;
};

void init_stack(struct stack *stack, size_t size) {
  stack->data = malloc(sizeof(void *) * size);
  stack->size = size;
  stack->top = 0;
}

void push(struct stack *stack, struct bracket point) {
  if (stack->top == stack->size - 1) {
    fprintf(stderr, "Stack overflow\n");
    exit(1);
  }
  stack->top++;
  stack->data[stack->top] = point;
}

struct bracket pop(struct stack *stack) {
  if (stack->top == -1) {
    fprintf(stderr, "Stack underflow\n");
    exit(1);
  }
  struct bracket point = stack->data[stack->top];
  stack->top--;
  return point;
}

void free_stack(struct stack *stack) {
  free(stack->data);
}