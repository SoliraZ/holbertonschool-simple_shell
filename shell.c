#include "shell.h"

/**
 * print_prompt - prints prompt
 */

void	print_prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("($) ");
		fflush(stdin);
	}
}
/**
 * tokenize - tokenizes user input
 * @user_input: user input
 *
 * Return: tokenized user input
 */

char	**tokenize(char *user_input)
{
	char **args = NULL;
	char *token;
	int i = 0;

	args = malloc(sizeof(char *) * 64);
	if (args == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	token = strtok(user_input, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = '\0';
	return (args);
}
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
