#include <assert.h>
#include <stack.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Node {
        uint8_t value;
        struct Node *next;
} Node;
typedef struct Stack {
        Node *head;
        uint64_t length;
} Stack;

void init_stack(Stack **stack) {
        *stack = calloc(1, sizeof(Stack));
        (*stack)->length = 0;
}
void push(Stack *stack, uint8_t value) {
        Node *node = calloc(1, sizeof(Node));
        node->value = value;
        node->next = stack->head;
        stack->head = node;
        stack->length++;
}
uint8_t pop(Stack *stack) {
        assert(stack->head != NULL);
        Node *tmp = stack->head;
        uint8_t value = tmp->value;
        stack->head = stack->head->next;
        free(tmp);
        stack->length--;
        return value;
}
uint64_t length(Stack *stack) { return stack->length; }