#ifndef INTERPRETER_H_
#define INTERPRETER_H_
typedef struct KemuriInterpreter KemuriInterpreter;
void init_interpreter(KemuriInterpreter **interpreter);
void set_instruction(KemuriInterpreter *interpreter, const char *instruction);
void run(KemuriInterpreter *interpreter);
#endif