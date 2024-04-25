#include "main.h"
#define MAX_TOKENS 69
#define MAX_TOKEN_LEN 100
/**
 * execute_command - Comparing and executing command
 * @tokens: The tokens array
 * @pointer: The command string
 * @env: Environment variables
 * Return: 1 succ, -1 if fails
 */
int execute_command(char **tokens, char *pointer, char **env)
{
	unsigned int e = 0;
	pid_t child_pid;
	int status;

	if (strcmp(tokens[0], "exit") == 0)
	{
		free(tokens);
		free(pointer);
		return (0);
	}

	if (strcmp(tokens[0], "env") == 0)
	{
		while (env[e])
		{
			write(1, env[e], strlen(env[e]));
			write(1, "\n", 1);
			e++;
		}
		return (1);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Child Process Failed");
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("execve");
			free(tokens);
			free(pointer);
			free_env(env);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	return (1);
}
/**
 * tokenization - This function tokenizes a string
 * @str: The string to tokenize
 * @delim: The delimiter characters
 * Return: Array of tokens
 * We #define above to specify the max num of tokens and the max lenght of each token.
 */
char **tokenization(char *str, char *delim)
{
	static char *tokens[MAX_TOKENS];
	char *token;
	int index = 0;

	token = strtok(str, delim);
	while (token != NULL && index < MAX_TOKENS)
	{
		tokens[index++] = token;
		token = strtok(NULL, delim);
	}
	tokens[index] = NULL;

	return (tokens);
}
/**
 * command_path - This function gets the full path of a command
 * @command: The command to find
 * @env: The environment variables
 * Return: The full path of the command if succ, NULL if fail
 */
char *command_path(char *command, char **env)
{
char *path = getenv("PATH");
char *path_copy;
char *token;

if (path == NULL)
{
	return NULL;
}

path_copy = strdup(path);

	if (path_copy == NULL)
	{
		return NULL;
	}

	token = strtok(path_copy, ":");

	(void) env;

	while (token != NULL) /* While token is NULL */
	{
		char *full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
