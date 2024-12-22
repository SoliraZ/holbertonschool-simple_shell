<<<<<<< HEAD
#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
=======
#ifndef SHELL_FILE
#define SHELL_FILE

#include <stdio.h>
#include <sys/types.h>
>>>>>>> bdc06814e620f2406c24cd4f24527390f35152be
#include <sys/stat.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
extern char **environ;
void print_prompt(void);
char **tokenize(char *user_input);
char *read_line(void);
void command(char **args, char *user_input);
void print_env(void);
=======
>>>>>>> bdc06814e620f2406c24cd4f24527390f35152be

#endif
