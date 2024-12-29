#include <interpreter.h>
#include <stack.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct KemuriInterpreter {
        char *instruction;
        Stack *stack;
} KemuriInterpreter;
static void XOR(KemuriInterpreter *interpreter);
static void NOT(KemuriInterpreter *interpreter);
static void dup(KemuriInterpreter *interpreter);
static void rot(KemuriInterpreter *interpreter);
static void hello(KemuriInterpreter *interpreter);
static void flush(KemuriInterpreter *interpreter);
static void operation(KemuriInterpreter *interpreter, char operation);
void init_interpreter(KemuriInterpreter **interpreter) {
        *interpreter = calloc(1, sizeof(KemuriInterpreter));
        init_stack(&(*interpreter)->stack);
}
void set_instruction(KemuriInterpreter *interpreter, const char *instruction) {
        char *prev = interpreter->instruction;
        uint64_t instr_length = strlen(instruction);
        interpreter->instruction = calloc(instr_length + 1, sizeof(char));
        memcpy(interpreter->instruction, instruction, instr_length);
        if (prev != NULL) {
                free(prev);
        }
}
void run(KemuriInterpreter *interpreter) {
        uint64_t index = 0;
        char ope = 0;
        while ((ope = interpreter->instruction[index++])) {
                operation(interpreter, ope);
        }
}
static void operation(KemuriInterpreter *interpreter, char operation) {
        switch (operation) {
                case '^':
                        XOR(interpreter);
                        break;
                case '~':
                        NOT(interpreter);
                        break;
                case '"':
                        dup(interpreter);
                        break;
                case '\'':
                        rot(interpreter);
                        break;
                case '`':
                        hello(interpreter);
                        break;
                case '|':
                        flush(interpreter);
                        break;
                default:
                        break;
        }
}
static void XOR(KemuriInterpreter *interpreter) {
        char fst = pop(interpreter->stack), snd = pop(interpreter->stack);
        push(interpreter->stack, fst ^ snd);
}

static void NOT(KemuriInterpreter *interpreter) {
        push(interpreter->stack, ~pop(interpreter->stack));
}
static void dup(KemuriInterpreter *interpreter) {
        char buf = pop(interpreter->stack);
        push(interpreter->stack, buf);
        push(interpreter->stack, buf);
}
static void rot(KemuriInterpreter *interpreter) {
        char x = pop(interpreter->stack), y = pop(interpreter->stack),
             z = pop(interpreter->stack);
        push(interpreter->stack, x);
        push(interpreter->stack, z);
        push(interpreter->stack, y);
}
static void hello(KemuriInterpreter *interpreter) {
        push(interpreter->stack, '!');
        push(interpreter->stack, 'd');
        push(interpreter->stack, 'l');
        push(interpreter->stack, 'r');
        push(interpreter->stack, 'o');
        push(interpreter->stack, 'w');
        push(interpreter->stack, ' ');
        push(interpreter->stack, ',');
        push(interpreter->stack, 'o');
        push(interpreter->stack, 'l');
        push(interpreter->stack, 'l');
        push(interpreter->stack, 'e');
        push(interpreter->stack, 'H');
}
static void flush(KemuriInterpreter *interpreter) {
        while (length(interpreter->stack)) {
                putchar(pop(interpreter->stack));
        }
}