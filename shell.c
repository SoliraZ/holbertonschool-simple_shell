#include "shell.h"

/**
 * find_command_path - Find command path
 * @command: Command
 *
 * Return: Command path
 */

char *find_command_path(char *command)
{
	char *path_env;
	char *path;
	char *token;
	int i = 0;
	char full_path[1024];

	while (command[i] != '\0')
	{
		if (command[i] == '/')
		{
			if (access(command, X_OK) == 0)
			{
				return (strdup(command));
			}
			return (NULL);
		}
		i++;
	}
	path_env = _getenv("PATH");
	if (!path_env)
	{
		return (NULL);
	}

	path = strdup(path_env);
	token = strtok(path, ":");

	while (token != NULL)
	{
		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

/**
 * execute_command - Execute command
 * @args: Array of arguments
 * @command_count: Command count
 */

void execute_command(char **args, int *command_count)
{
	pid_t pid;
	char *path = find_command_path(args[0]);

	(*command_count)++;
	if (path == NULL)
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", *command_count, args[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", *command_count, args[0]);
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("./hsh not found");
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

/**
 * handle_builtin_commands - Handle built-in commands
 * @args: Array of arguments
 * @command_count: Command count
 * @user_input: User input
 */

void handle_builtin_commands(char **args, int *command_count, char *user_input)
{
	if (args[0] != NULL)
	{
		if (strncmp(args[0], "exit", 4) == 0)
		{
			int status = 0;

			if (args[1] != NULL)
			{
				status = atoi(args[1]);
			}
			free_args(args);
			free(user_input);
			exit(status);
		}
		else if (strncmp(args[0], "env", 3) == 0)
		{
			print_env();
			(*command_count)++;
		}
		else
		{
			if (strncmp(args[0], "cd", 2) == 0)
			{
				cd_command(args);
				(*command_count)++;
			}
			else
			{
				execute_command(args, command_count);
			}
		}
	}
}

/**
 * handle_signint - Handle signal interrupt
 * @signint: Signal interrupt
 */

void handle_signint(int signint)
{
	(void)signint;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - simple shell
 *
 * Return: Always 0
 */

int main(void)
{
	char **args = NULL;
	char *user_input = NULL;
	int command_count = 0;

	signal(SIGINT, handle_signint);
	while (1)
	{
		print_prompt();
		user_input = read_line();
		args = tokenize(user_input);
		handle_builtin_commands(args, &command_count, user_input);
		free_args(args);
		free(user_input);
	}
	return (0);
}

