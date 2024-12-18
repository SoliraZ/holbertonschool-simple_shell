#include "shell.h"

/**
 * main - Simple shell main function.
 *
 * Return: 0 on sucess and 1 on error.
 */

int	main(void)
{
	char **args = NULL, *user_input = NULL;
	char *token;
	size_t size_alloc = 0;
	int i, r_getline;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("($) ");
			fflush(stdin);
		}
		r_getline = getline(&user_input, &size_alloc, stdin);
		if (r_getline == -1)
		{
			free(user_input);
			perror("getline error");
			exit(EXIT_FAILURE);
		}
		user_input[strcspn(user_input, "\n")] = '\0';
		args = malloc(sizeof(char *) * 64);
		if (args == NULL)
		{
			perror("malloc error");
			exit(EXIT_FAILURE);
		}
		token = strtok(user_input, " ");
		i = 0;
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = '\0';
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
