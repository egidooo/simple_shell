#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_ARGS 10
#define BUFFER_SIZE 1024
/**
* main - simple shell program entry point
* Description: simple shell program written in C
* for UNIX based systems. Program written by
* Egide Kwizera and Hafsa Yussuf
* Return:Status code 0 if successful
*/
int main(void)
{
char buffer[BUFFER_SIZE];
char *args[MAX_ARGS + 1];
pid_t pid;
while (1)
{
printf("alx_shell$ ");
fflush(stdout);
if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
{
printf("\n");
exit(EXIT_SUCCESS);
}
buffer[strcspn(buffer, "\n")] = 0;
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
int i = 0;
char *token = strtok(buffer, " ");
while (token != NULL && i < MAX_ARGS)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;
execvp(args[0], args);
perror(args[0]);
exit(EXIT_FAILURE);
}
else
{
int status;
if (waitpid(pid, &status, 0) == -1)
{
perror("waitpid");
exit(EXIT_FAILURE);
}
}
}
return (0);
}
