#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *strtok(char *str, const char *delim);
void execmd(char **argv);
