#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * exit_func - checks for the "exit" command and exits if found
 * @args: array of command arguments
 * @user_input: the raw user input string
 */
void exit_func(char **args, char *user_input)
{
	if (args[0] && strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(user_input);
		exit(0);
	}
}

/**
 * main - entry point
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
	char **args = NULL;
	char *user_input = NULL;
	pid_t pid;

	while (1)
	{
		print_prompt();
		user_input = read_line();
		args = tokenize(user_input);

		exit_func(args, user_input);

		if (args[0] != NULL)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("fork error");
				free(args);
				free(user_input);
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{
				if (execvp(args[0], args) == -1)
				{
					fprintf(stderr, "./hsh: command not found: %s\n", args[0]);
					free(args);
					free(user_input);
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
