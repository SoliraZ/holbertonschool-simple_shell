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

void print_prompt(void);
char **tokenize(char *user_input);
char *read_line(void);
int exec_cmd(char **cmd, char **env);
extern char **environ;

#endif
