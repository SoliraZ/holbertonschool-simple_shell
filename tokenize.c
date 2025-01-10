#include "shell.h"

/**
 * tokenize - tokenizes user input
 * @user_input: user input
 *
 * Return: tokenized user input
 */

char	**tokenize(char *user_input)
{
	char **args = NULL;
	char *token;
	int i = 0;

	args = malloc(sizeof(char *) * 64);
	if (args == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	token = strtok(user_input, " ");
	while (token != NULL)
	{
		args[i++] = strdup(token);
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}

/**
 * free_args - Frees the memory allocated for arguments.
 * @args: Array of arguments.
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}
