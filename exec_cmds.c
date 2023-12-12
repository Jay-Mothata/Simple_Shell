#include "cj_shell.h"

/**
 * exec_cmds - Executes a command specified by argv
 * @lineptr: THe original input line containing the command
 * @argv: Array of strings representing the command and its arguements
 */

void exec_cmds(char *lineptr, char *argv[])
{
	pid_t child;
	int status;

	if (access(argv[0], X_OK) == -1)
	{
		fprintf(stderr, "%s: %s: not found\n", argv[0], lineptr);
		return;
	}

	child = fork();

	if (child == -1)
		return;

	if (child == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
			perror("execve");
	}
	else
	{
		waitpid(child, &status, 0);
	}
}
