#include "shell.h"
#include <sys/wait.h>
/**
 * read_line - read a line from stdin
 *
 * Return: pointer that points to a str with the line content
 */
int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	pid_t pid;
	int status;
	char **args = NULL;

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
}
