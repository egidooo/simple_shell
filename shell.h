#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *strtok(char *str, const char *delim);
void execmd(char **argv);
char *get_location(char *command);
