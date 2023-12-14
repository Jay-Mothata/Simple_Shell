#include "cj_shell.h"

/**
 * exec_cmds - Executes a command specified by argv
 * @lineptr: The original input line containing the command
 * @argv: Array of strings representing the command and its arguements
 */

void exec_cmds(char *lineptr, char *argv[])
{
	pid_t child;
	int status;

	/* Get the full path of the command using get_path */
	/* get_path(&argv[0]); */

	if (access(argv[0], X_OK | R_OK) == -1)
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
		{
			perror("execve");
			/* _exit(EXIT_FAILURE); */
		}
	}
	else
	{
		waitpid(child, &status, 0);
	}
}
