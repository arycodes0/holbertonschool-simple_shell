#include "main.h"

/*
 * execute_command - comparing and executing command
 * @tokens: tokens array
 * @pointer: command and input string
 * @env: environment variables
 *
 */

void execute_command(char **tokens, char *pointer, char **env)
{
	 unsigned int e = 0;
	pid_t child_pid;
	int status;

	if (strcmp(tokens[0], "exit") == 0)
	{
		free_array(tokens);
		free(pointer);
		exit(0);
	}

	if (strcmp(tokens[0], "env") == 0)
	{
		while (env[i])
		{
			write(1, env[e], _strlen(env[e]));
			write(1, "\n", 1);
			e++;
		}
		return;
	}

	child_pid = fork();
	if (child_pid == -1)
		perror("child process failed");
	else if (child_pid == 0)
	{
		if (execvp(tokens[0], tokens) == -1)
		{
			perror("execvp");
			free_array(tokens);
			free(pointer);
			exit(EXIT_FAILURE);
		}
	}
else
	{
		wait(&status);
	}
}
