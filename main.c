#include "main.h"

/**
 * main - Runs the Simple Shell
 * @ac: Argument count
 * @av: Argument vector
 * @env: environment
 * Return: 0
 */
int main(int ac, char **av,  char **env)
{
	char *pointer = NULL, **tokens = NULL;
	int flag;
	size_t n = 0;
	void av;
	void ac;

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);

		flag = getline(&pointer, &n, stdin);

		//Victor, here goes the if statement to handle EOF//

		if (pointer[0] == '\n' || pointer[0] == ' ')
		{
			free(pointer);
			pointer = NULL;
			continue;
		}

		tokens = tokenization(pointer, " \n");
		comp_exec(tokens, pointer, env);
	}
	return (0);
}
