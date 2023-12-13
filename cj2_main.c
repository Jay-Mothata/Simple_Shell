#include "cj_shell.h"

/**
 * handle_user_input - Prompts the user for input and reads the command line.
 * @lineptr: Pointer to the input string.
 * @len: Length of the input string.
 */

void handle_user_input(char **lineptr, size_t *len)
{
	cj_print("Shell$ ");
	getline(lineptr, len, stdin);
	if ((*lineptr)[strlen(*lineptr) - 1] == '\n')
		(*lineptr)[strlen(*lineptr) - 1] = '\0';
}

/**
 * process_command - Tokenizes and executes the user-entered command.
 * @lineptr: Pointer to the input string.
 */

void process_command(char *lineptr)
{
	char **commands = tokenize(lineptr, " ");

	if (commands != NULL && commands[0] != NULL)
	{
		if (strcmp(commands[0], "exit") == 0)
		{
			free_cmds(commands);
			cj_exit();
		}

		exec_cmds(lineptr, commands);
		free_cmds(commands);
	} else
	{
		cj_print("Invalid input.\n");
	}
}

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *lineptr = NULL;
	size_t len = 0;

	while (1)
	{
		handle_user_input(&lineptr, &len);
		process_command(lineptr);
		free(lineptr);
		lineptr = NULL;
	}

	return (0);
}
