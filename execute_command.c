#include "main.h"
#define MAX_TOKENS 69
#define MAX_TOKEN_LEN 100
/**
 * execute_command - Comparing and executing command
 * @tokens: The tokens array
 * @env: Environment variables
 * Return: 1 succ, -1 if fails
 */
int execute_command(char **tokens,  char **env)
{
	unsigned int e = 0;
	pid_t child_pid;

	if (strcmp(tokens[0], "exit") == 0)
	{
		free(*tokens);
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
		free(*tokens);
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
		if (execve(tokens[0], tokens, env) == -1) /*El error esta en este if */
		{
			perror("execve");
			free(*tokens);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

/**
 * tokenization - This function tokenizes a string
 * @str: The string to tokenize
 * @delim: The delimiter characters
 * Return: Array of tokens
 * We #define above to specify the max num
 *  of tokens and the max lenght of each token.
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
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");

	(void)env;

	while (token != NULL)
	{
		char *full_path = malloc(strlen(token) + strlen(command) + 2);

		if (full_path == NULL)
		{
			perror("malloc");
			printf("Este esta command_path, encima de freepathcopy");
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			printf("Esta en command_path, debajo de fullpath");
			free(path_copy);

			return (full_path);
		}
		printf("Esta en command_path, encima de fullpath");
		free(full_path);
		token = strtok(NULL, ":");
	}
	printf("Esta en command_path, al final del file de command_path");
	free(path_copy);
	return (NULL);
}
