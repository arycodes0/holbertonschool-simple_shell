#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> /* We use this for the getline */
#include <stdlib.h> /* We use this for the exit */
#include <unistd.h> /* We use this for the write, fork, execve, and isatty*/
#include <string.h> /* We use this for the strtok*/

/* PROTOTYPES */
int main(int ac, char **av,  char **env);
int execute_command(char **tokens, char *pointer, char **env);

#endif
