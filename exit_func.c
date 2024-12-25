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
	if (args && args[0] && strcmp(args[0], "exit") == 0)
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

	while (1)
	{
		pid_t pid;

		print_prompt();

		user_input = read_line();
		if (!user_input)
		{
			perror("read_line");
			continue;
		}

		args = tokenize(user_input);
		if (!args || !args[0])
		{
			free(user_input);
			free(args);
			continue;
		}
	exit_func(args, user_input);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(args);
		free(user_input);
		continue;
	}

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
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
	free(user_input);
	free(args);
	}

	return (0);
}
