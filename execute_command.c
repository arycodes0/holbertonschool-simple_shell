#include "main.h"
#define MAX_TOKENS 69
#define MAX_TOKEN_LEN 100
/**
 * run_command - Runs the command
 * @tokens: The tokens array
 * @sta: status struct
 * @env: Environment variables
 * Return: 1 succ, -1 if fails
 */
void run_command(char **tokens, struct stat sta, char **env)
{
	char **temp;
	unsigned int e = 0;
		if (tokens[0][0] != '/') 
		{
			temp = command_path(tokens[0]); 
			for (e = 0; temp[e] != NULL; e++)
			{	
				if (stat(temp[e], &sta) == 0 && sta.st_mode & S_IXUSR)
				{
					free(tokens[0]);
					tokens[0] = strdup(temp[e]);
				}
			}
		}
		if (execve(tokens[0], tokens, env) == -1)
		{
			perror("execve");
			free_array(tokens);
			exit(EXIT_FAILURE);
		}
}


/**
 * execute_command - Comparing and executing command
 * @tokens: The tokens array
 * @env: Environment variables
 * Return: 1 succ, -1 if fails
 */
int execute_command(char **tokens, char **env)
{
	unsigned int e = 0;
	struct stat sta;
	pid_t child_pid;

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
		run_command(tokens, sta, env);
		free_array(tokens);

		exit(98);
	}
	else
	{
		wait(NULL);
	}
	return (1);
}

/**
 * tokenization - This function tokenizes a string
 * @str: The string to tokenize
 * @delim: The delimiter characters
 * Return: Array of tokens
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
 * command_path - This function handles path
 * @command: command to join to path
 *
 * Return: An array of strings
 */
char **command_path(char *command)
{
	char *directory2;
	char **directory;
	char *path;
	char *path2;
	char *token;
	int i;
	int count;

	count = 1;
	path = get_env("PATH");
	path2 = strdup(path);
	token = strtok(path2, ":");
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
			count++;
	}
	directory = malloc(sizeof(char *) * (count + 1));
	for (i = 0; token != NULL; i++)
	{
		directory2 = malloc(strlen(token) + strlen(command) + 2);
		strcpy(directory2, token);
		strcat(directory2, "/");
		strcat(directory2, command);
		directory[i] = directory2;
		token = strtok(NULL, ":");
	}
	directory[count] = NULL;
	free(path);
	return (directory);
}

/**
 * get_env - searches for a variable
 * @name: name of variable
 *
 * Return: pointer to variable
 */
char *get_env(char *var_name)
{
	int i, j;
	char *value;
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			if (environ[i][j] != var_name[j])
			{
				break;
			}
			else if (environ[i][j + 1] == '=')
			{
				if (var_name[j + 1] == '\0')
				{
					value = strdup(&environ[i][j + 2]);
					return (value);
				}

			}
		}
	
	}
	return (NULL);
}
