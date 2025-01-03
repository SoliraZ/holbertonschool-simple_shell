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
	char full_path[1024];

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
		{
			return (strdup(command));
		}
		return (NULL);
	}

	path_env = getenv("PATH");
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
 */

void execute_command(char **args)
{
	pid_t pid;
	char *path = find_command_path(args[0]);

	if (path == NULL)
	{
		fprintf(stderr, "./hsh: %s: not found\n", args[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("./hsh not found\n");
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
 * @user_input: User input
 */

void handle_builtin_commands(char **args, char *user_input)
{
	if (args[0] != NULL)
	{
		if (strncmp(args[0], "exit", 4) == 0)
		{
			free_args(args);
			free(user_input);
			exit(0);
		}
		else if (strncmp(args[0], "env", 3) == 0)
		{
			print_env();
		}
		else
		{
			execute_command(args);
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
 * main - Simple Shell
 *
 * Return: Always 0
 */

int main(void)
{
	char **args = NULL;
	char *user_input = NULL;

	signal(SIGINT, handle_signint);
	while (1)
	{
		print_prompt();
		user_input = read_line();
		args = tokenize(user_input);
		handle_builtin_commands(args, user_input);
		free_args(args);
		free(user_input);
	}
	return (0);
}

