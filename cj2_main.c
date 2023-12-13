#include "cj_shell.h"

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	/* Variables for input */
	char *lineptr = NULL;
	size_t len = 0;

	/* Shell main loop */
	while (1)
	{
		cj_print("Shell$ ");
		getline(&lineptr, &len, stdin);

		/* Remove the newline character at the end */
		if (lineptr[strlen(lineptr) - 1] == '\n')
			lineptr[strlen(lineptr) - 1] = '\0';

		/* Tokenize the input command */
		char **commands = tokenize(lineptr, " ");

		if (commands != NULL && commands[0] != NULL)
		{
			/* Check for built-in commands */
			if (strcmp(commands[0], "exit") == 0)
			{
				free_cmds(commands);
				cj_exit();
			}

			/* Execute the command */
			exec_cmds(lineptr, commands);
			free_cmds(commands);
		}
		else
		{
			cj_print("Invalid input.\n");
		}

		free(lineptr);
		lineptr = NULL;
	}

	return (0);
}
