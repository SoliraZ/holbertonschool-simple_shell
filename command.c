#include "shell.h"

/**
 * command - Checks for the "exit" command and exit if found.
 * @args: Array of command arguments.
 * @user_input: User input string.
 */

void	command(char **args, char *user_input)
{
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(user_input);
		exit(0);
	}
	if (strcmp(args[0], "env") == 0)
	{
		print_env();
	}
	if (strcmp(args[0], "test") == 0)
	{
		printf("test\n");
	}
}
