#include "shell.h"

/**
 * cd_command - Change directory
 * @args: Array of arguments
 *
 * Return: 0 on success, 1 on failure
 */

int cd_command(char **args)
{
	char *dir, cwd[1024];

	if (args[1] == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			fprintf(stderr, "cd: No home directory.\n");
			return (1);
		}
	}
	dir = args[1];
	if (chdir(dir) != 0)
	{
		perror("cd");
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		setenv("PWD", cwd, 1);
	else
	{
		perror("getcwd");
		return (1);
	}
	return (0);
}
