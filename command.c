#include "shell.h"

/**
 * command - Checks for the "exit" command and exit if found.
 * @args: Array of command arguments.
 * @user_input: User input string.
 */

void	command(char **args, char *user_input)
{
	if (strncmp(args[0], "exit", 4) == 0)
	{
		free(args);
		free(user_input);
		exit(0);
	}
	if (strncmp(args[0], "env", 3) == 0)
	{
		print_env();
	}
}
