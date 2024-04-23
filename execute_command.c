#include "main.h"

/*
 * execute_command - comparing and executing command
 * @tokens: tokens array
 * @pointer: command and input string
 * @env: environment variables
 */
int execute_command(char **tokens, char *pointer, char **env)
{
	unsigned int e = 0;
	pid_t child_pid;
	int status;

	if (strcmp(tokens[0], "exit") == 0)
	{
		free_array(tokens);
		free(pointer);
		return (0);
	}

	if (strcmp(tokens[0], "env") == 0)
	{
		while (env[e])
		{
			write(1, env[e], _strlen(env[e]));
			write(1, "\n", 1);
			e++;
		}
		return (1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("child process failed");
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, env) == -1)
		{
			perror("execve");
			free_array(tokens);
			free(pointer);
			free_array(env);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	return (1);
}
