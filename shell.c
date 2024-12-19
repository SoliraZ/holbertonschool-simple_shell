#include "shell.h"

/**
 * main - entry point
 *
 * Return: 0 on success, 1 on failure
 */

int	main(void)
{
	char **args = NULL;
	char *user_input = NULL;
	pid_t pid;

	while (1)
	{
		print_prompt();
		user_input = read_line();
		args = tokenize(user_input);
		if (args[0] != NULL)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("fork error");
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{
				if (execvp(args[0], args) == -1)
				{
					perror("execvp error");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				int status;

				waitpid(pid, &status, 0);
			}
		}
		free(args);
	}
	free(user_input);
	return (0);
}
