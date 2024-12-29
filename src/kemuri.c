#include <interpreter.h>
#include <stdio.h>
#include <string.h>

int main() {
        KemuriInterpreter *interpreter;
        char buf[256] = {'\0'};
        init_interpreter(&interpreter);
        printf("> ");
        while (scanf("%s", buf)) {
                set_instruction(interpreter, buf);
                run(interpreter);
                printf("\n> ");
                memset(buf, 0, sizeof(char) * 256);
        }
}