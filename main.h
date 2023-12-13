#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

typedef struct stat stat_t;

int getadd(char **add, char **environ);
char **getav(char *fileptr, char **environ);

/* String Utils */
int _strcmp(char *s1, char *s2);
char *_getenv(char *name, char **environ);

#endif
