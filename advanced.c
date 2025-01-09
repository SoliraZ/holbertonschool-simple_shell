#include "shell.h"

/**
 * cd_command - Change directory
 * @args: Array of arguments
 *
 * Return: 1 on success, 0 on failure
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
			return (0);
		}
	}
	else if (strcmp(args[1], "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if (dir == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set.\n");
			return (0);
		}
		printf("%s\n", dir);
	}
	else
		dir = args[1];
	if (chdir(dir) != 0)
	{
		perror("cd");
		return (0);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		setenv("PWD", cwd, 1);
	else
	{
		perror("getcwd");
		return (0);
	}
	return (1);
}
