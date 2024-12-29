#ifndef STACK_H_
#define STACK_H_
#include <stdint.h>
typedef struct Node Node;
typedef struct Stack Stack;
void init_stack(Stack **stack);
void push(Stack *stack, uint8_t value);
uint8_t pop(Stack *stack);
uint64_t length(Stack *stack);
#endif