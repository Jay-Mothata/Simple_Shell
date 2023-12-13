#include "cj_shell.h"

/**
 * tokenize - Splits a string into an array of tokens based on a delimeter
 * @str: The input string to be tokenized
 * @delim: The delimeter used to split the string
 *
 * Return: An array of strings 9tokens) or NULL if input is invalid
 */

char **tokenize(char *str, const char *delim)
{
	char **commands = NULL, *token, *dup_str;
	size_t n_tokens, i;

	if (str == NULL || *str == '\0')
		return (NULL);

	dup_str = strdup(str);
	token = strtok(dup_str, delim);

	n_tokens = 0;
	while (token != NULL)
	{
		++n_tokens;
		token = strtok(NULL, delim);
	}
	free(dup_str);

	if (n_tokens > 0)
	{
		commands = malloc(sizeof(char *) * (n_tokens + 1));
		if (commands == NULL)
			exit(EXIT_FAILURE);

		token = strtok(str, delim);
		i = 0;

		while (token != NULL)
		{
			commands[i] = strdup(token);
			token = strtok(NULL, delim);
			i++;
		}
		commands[i] = NULL;
	}
	return (commands);
}
