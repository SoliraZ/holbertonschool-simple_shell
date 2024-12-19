#include "shell.h"

/**
 * exit_func - Checks for the "exit" command and exit if found.
 * @args: Array of command arguments.
 * @user_input: User input string.
 */

void	exit_func(char **args, char *user_input)
{
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(user_input);
		exit(0);
	}
}
