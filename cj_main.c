#include "cj_shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always returns EXIT_SUCCESS
 */

int main(void)
{
	char *cmd;

	while (true)
	{
		dispwait_prompt();
		cmd = reads_from_user();

		if (cmd != NULL && *cmd != '\0')
		{
			executes_cmd(cmd);
		}

		free(cmd); /*Frees memory allocated for user input */
	}

	return (EXIT_SUCCESS);
}
