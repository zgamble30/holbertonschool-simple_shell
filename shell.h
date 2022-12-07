#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include "sys/wait.h"

char **shell_split_line(char *line);
char *shell_read_line(void);
void shell_exec(char **args);

#endif
