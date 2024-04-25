#include "main.h"

/**
 * free_array - Function to free an array
 * @tokens: Array to free
 * Return: Void
 */
void free_array(char **tokens)
{
  int i = 0;

  while (tokens[i])
  {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
