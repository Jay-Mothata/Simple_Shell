#include "cj_shell.h"

/**
 * dispwait_prompt - displayes the prompt of the shell
 */

void dispwait_prompt(void)
{
	cj_print("CJ $");
}

/**
 * reads_from_user - Reads command from the user
 *
 * Return: A dynamically allocated string containing the the user's input
 */

char *reads_from_user(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t read;

	read = getline(&line, &bufsize, stdin);

	if (read == -1)
	{
		cj_print("\n"); /* Handles EOF condition */
		free(line); /* Free memory in case of error */
		exit(EXIT_SUCCESS);
	}

	return (line);
}

/**
 * executes_cmd - Execute a command in a child process
 * @cmd: THe command to be executed
 */

void executes_cmd(char *cmd)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		/* Child process */
		char *args[2];

		args[0] = cmd;

		args[1] = NULL;

		execve(cmd, args, NULL);
		perror("cj_shell"); /* Handles execution errors */
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("cj_shell"); /* Handles fork errors */
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, WUNTRACED);
	}
}
