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
	int res_getline, i;

	res_getline = getline(&user_input, &size_alloc, stdin);
	if (res_getline == EOF)
	{
		free(user_input);
		if (isatty(STDIN_FILENO))
			putchar('\n');
		exit(EXIT_SUCCESS);
	}
	if (res_getline == -1)
	{
		perror("getline error");
		exit(EXIT_FAILURE);
	}
	i = 0;
	size_t len = strlen(user_input);
	if (len > 0 && user_input[len - 1] == '\n')
		user_input[len - 1] = '\0';
	return (user_input);
}
