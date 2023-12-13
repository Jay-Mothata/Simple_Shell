#include "cj_shell.h"

/**
 * get_path - Find the full path of a command in the PATH directories
 * @cmd: A pointer to the string containing the command to get to the full path
 */

void get_path(char **cmd)
{
	char *current_directory = NULL, *path = NULL, *path_directories, *str_duplicator;

	if (*cmd == NULL || cmd == NULL)
		fprintf(stderr, "Invalid Command\n");

	path_directories = getenv("PATH");
	if (path_directories == NULL)
		fprintf(stderr, "PATH environment variable not found\n");

	str_duplicator = strdup(path_directories);
	if (str_duplicator == NULL)
		fprintf(stderr, "Memory allocation failed\n");

	current_directory = strtok(str_duplicator, ":");

	while (current_directory != NULL)
	{
		path = malloc(sizeof(char) * (strlen(*cmd) + strlen(current_directory) + 2));
		if (path == NULL)
			fprintf(stderr, "Memory allocation failed\n");

		sprintf(path, "%s/%s", current_directory, *cmd);

		if (access(path, X_OK) == 0)
		{
			free(*cmd);
			*cmd = strdup(path);
			break;
		}
		free(path);
		current_directory = strtok(NULL, ":");
	}
	free(str_duplicator);
}
