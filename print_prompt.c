#include "shell.h"

/**
 * print_prompt - prints prompt
 */

void	print_prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("$ ");
		fflush(stdin);
	}
}
