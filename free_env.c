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
		printf("Este es el free que va antes en el free_env");
		i++;
	}
	printf("Esta en freeenv, encima");
	free(env);
	printf("Esta en freeenv, debajo");
}

