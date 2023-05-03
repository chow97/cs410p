/*
The init_stack() function initializes a stack with the given size.

The push() function pushes the given value onto the stack.

The pop() function pops the top element off the stack and returns its value.

The free_stack() function frees the memory allocated for the stack.
*/
#include <stdio.h>
#include <stdlib.h>

// Define the bracket struct
struct bracket {
    double angle;
    double x;
    double y;
};

// Define the stack struct
struct stack {
    int top;
    int capacity;
    struct bracket* array;
};

// Create a new stack
struct stack* createStack(int capacity) {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct bracket*)malloc(stack->capacity * sizeof(struct bracket));
    return stack;
}

// Check if the stack is empty
int isEmpty(struct stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push an element onto the stack
void push(struct stack* stack, struct bracket item) {
    if (isFull(stack)) {
        printf("Error: Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Pop an element off the stack
struct bracket pop(struct stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

// Get the top element of the stack without popping it
struct bracket peek(struct stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top];
}