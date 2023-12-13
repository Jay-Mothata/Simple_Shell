#include "cj_shell.h"

/**
 * handle_user_input - Prompts the user for input and reads the command line.
 * @lineptr: Pointer to the input string.
 * @len: Length of the input string.
 */

void handle_user_input(char **lineptr, size_t *len)
{
	ssize_t n_read;
	size_t cmd_count = 0;

	if (isatty(STDIN_FILENO))
		cj_print("CJ_$ ");
	fflush(stdout);
	n_read = getline(lineptr, len, stdin);
	++cmd_count;

	if (n_read == -1)
	{
		free(*lineptr);
		*lineptr = NULL;
		if (isatty(STDIN_FILENO))
			cj_print("\n");
		exit(EXIT_SUCCESS);
	}
	(*lineptr)[n_read - 1] = '\0';
}

/**
 * process_command - Tokenizes and executes the user-entered command.
 * @lineptr: Pointer to the input string.
 */

void process_command(char *lineptr)
{
	char **commands;

	commands = tokenize(lineptr, " ");

	if (commands != NULL && commands[0] != NULL)
	{
		/* get_path(&commands[0]); */

		if (strcmp(commands[0], "exit") == 0)
		{
			free_cmds(commands);
			free(lineptr);
			exit(0);
		}
		else
		{
			exec_cmds(lineptr, commands);
		}

		free_cmds(commands);
	}
	else
	{
		cj_print("Invalid input.\n");
	}
}

/**
 * main - Entry point for the simple shell
 * @argc: Number of command-line arguements
 * @argv: Array of command-line arguements
 * Return: Always 0 (success)
 */

int main(int argc, char *argv[])
{
	char *lineptr = NULL;
	size_t n = 0;

	(void)argc, (void)argv;

	while (true)
	{
		handle_user_input(&lineptr, &n);

		if (*lineptr == '\0')
			continue;

		process_command(lineptr);
		free(lineptr);
		lineptr = NULL;
	}
	return (0);
}
