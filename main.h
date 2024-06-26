#ifndef MAIN_H
#define MAIN_H

#define MAX_TOKENS 69
#define MAX_TOKEN_LEN 100
/*
 * MAX_TOKENS and MAX_TOKEN_LEN is added here for accessibility if needed,
 * and for the sake of organizing
 */

#include <stdio.h> /* We use this for the getline */
#include <stdlib.h> /* We use this for the exit */
#include <unistd.h> /* We use this for the write, fork, execve, and isatty */
#include <string.h> /* We use this for the strtok*/
#include <stddef.h> /* We use this for size_t variable type */
#include <sys/wait.h> /* We use this for the wait */
#include <sys/stat.h>
#include <sys/types.h>

/* PROTOTYPES */
int main(int ac, char **av);
int execute_command(char **tokens, char **env);
char **tokenization(char *str, char *delim);
void free_env(char **env);
char **command_path(char *command);
void free_array(char **tokens);
char *get_env(char *name);


extern char **environ;

#endif
