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
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = '\0';
	return (args);
}
