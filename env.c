#include "shell.h"

/**
 * print_env - print the environment
 */

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
/**
 * _getenv - get the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: 0 on success, 1 on failure
 */

char *_getenv(const char *name)
{
	int i;
	size_t len = strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (environ[i] + len + 1);
		}
	}
	return (NULL);
}
