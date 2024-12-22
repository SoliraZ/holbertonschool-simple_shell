#include "shell.h"
<<<<<<< HEAD

/**
 * main - Entry point for the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char **args = NULL;
	char *user_input = NULL;
	char *command_path == NULL;
	pid_t pid;

	while (1)
	{
		print_prompt();
		user_input = read_line();
		args = tokenize(user_input);
		if (strcmp(args[0], "exit") == 0
				|| strcmp(args[0], "env") == 0 || strcmp(args[0], "test") == 0)
			command(args, user_input);

		else
		{
			pid = fork();
			if (pid == -1)
			{
				perror("fork error");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				if (execve(args[0], args, environ) == -1)
				{
					fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				int status;

				waitpid(pid, &status, 0);
			}
		}
		else
		{
			char *path = find_path(args[0]);

			if (path)
			{
				perror("fork error");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				if (execve(path, args, environ) == -1)
				{
					fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				int status;

				waitpid(pid, &status, 0);
			}
			free(path);
		}
		else
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		}
		free(args);
	}
	free(user_input);
	return (0);
=======
#include <sys/wait.h>

#define BUFFER_size 1024
/**
 * main - Entry of the Shell program
 *
 * Return: pointer that points to a str with the line content
 */
int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	pid_t pid;
	int status;
	char *args[BUFFER_SIZE];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("($) ");
			fflush(stdin);
		}
		else if (getline(&line, &bufsize, stdin) == -1)
		{
			if (feof(stdin))
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			else
			{
				free(line);
				perror("error while reading the line from stdin");
				exit(EXIT_FAILURE);
			}
		}
	}
	pid = fork();
	if (pid ==  0)
	{
	if (execvp(args[0], args) == -1)
	{
	perror("error in new_process: child process");
	}
	exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error in new_process: forking");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (line);
>>>>>>> bdc06814e620f2406c24cd4f24527390f35152be
}
