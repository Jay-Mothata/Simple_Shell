#include "cj_shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Number of command-line arguements
 * @argv: Array of command-line arguements
 * Return: Always 0 (success)
 */

int main(int argc, char *argv[])
{
	char *lineptr = NULL, **commands = NULL;
	size_t n = 0, cmd_count = 0;
	ssize_t n_read;

	(void)argc, (void)argv;
	while (true)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		fflush(stdout);
		n_read = getline(&lineptr, &n, stdin);
		++cmd_count;

		if (n_read == -1)
		{
			free(lineptr);
			lineptr = NULL;
			if (isatty(STDIN_FILENO))
				printf("\n");
			exit(0);
		}
		lineptr[n_read - 1] = '\0';

		if (*lineptr == '\0')
			continue;

		commands = tokenize(lineptr, " ");
		if (commands == NULL)
			continue;

		exec_cmds(lineptr, commands);
		free(lineptr);
		free_cmds(commands);
		commands = NULL;
		lineptr = NULL;
	}
	return (0);
}
