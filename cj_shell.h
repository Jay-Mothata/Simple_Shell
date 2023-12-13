#ifndef CJ_SHELL_H
#define CJ_SHELL_H

/* Standard Libraries */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/* External enviroment */
extern char **environ;

/* Function prototypes */
char **tokenize(char *str, const char *delim);
void free_cmds(char **cmds);
void exec_cmds(char *lineptr, char *argv[]);
void cj_print(const char *message);
void get_path(char **cmd);
void handle_user_input(char **lineptr, size_t *len);
void process_command(char *lineptr);

#endif /* CJ_SHELL_H */
