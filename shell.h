#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

extern char **environ;
void print_prompt(void);
char **tokenize(char *user_input);
char *read_line(void);
void command(char **args, char *user_input);
void print_env(void);

#endif
