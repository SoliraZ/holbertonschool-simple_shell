#include "shell.h"

/**
 * read_line - reads a line from stdin
 *
 * Return: user input
 */

char	*read_line(void)
{
	char *user_input = NULL;
	size_t size_alloc = 0;

	if (getline(&user_input, &size_alloc, stdin) == -1)
	{
		perror("getline error");
		exit(EXIT_FAILURE);
	}
	user_input[strcspn(user_input, "\n")] = '\0';
	return (user_input);
}
