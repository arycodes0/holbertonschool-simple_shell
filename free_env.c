#include "main.h"

/**
 * free_env - Free the environment array
 * @env: The environment array to free
 * This func handles execve failure scenario.
 */
void free_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		free(env[i]);
		i++;
	}
	free(env);
}

