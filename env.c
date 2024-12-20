#include "shell.h"

/**
 * print_env- entry point
 *
 * Return: 0 on success, 1 on failure
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
