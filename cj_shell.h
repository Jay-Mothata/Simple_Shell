#ifndef CJ_SHELL_H
#define CJ_SHELL_H

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */
void cj_print(const char *output);
void dispwait_prompt(void);
char *reads_from_user(void);
void executes_cmd(char *cmd);

#endif /* CJ_SHELL_H */
