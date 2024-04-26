#include "main.h"

/**
 * main - Runs the Simple Shell
 * @ac: Argument count
 * @av: Argument vector
 * Return: 0
 */
int main(int ac, char **av)
{
	char *pointer = NULL, **tokens = NULL;
	int flag;
	size_t n = 0;
	(void) av;
	(void) ac;

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);

		flag = getline(&pointer, &n, stdin);

		if (flag == -1)
		{
			free(pointer);
			break; /* Exit the loop */
		}
		if (pointer[0] == '\n' || pointer[0] == ' ')
		{
			free(pointer);
			pointer = NULL;
			continue;
		}
		tokens = tokenization(pointer, " \n");
		if (strcmp(tokens[0], "exit") == 0)
		{
			free(*tokens);
			free(pointer);
			exit(0); /* Here we exit the shell */
		}
		execute_command(tokens, environ);
	}
	return (0);
}
