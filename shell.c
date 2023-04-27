#include "shell.h"
#include <unistd.h>

/**
 * main - displays the prompt to the user
 * @ac: argument count
 * @argv: argument vector
 * Return: 0
 */

int main(int ac, char **argv)
{
	char *prompt = "shell$";
	char *lineptr = NULL, *lineptr_cp = NULL;
	size_t n = 0;
	ssize_t char_read;
	const char *delim = " \n";
	int num_token = 0, k;
	char *token;

	(void)ac;
	while (1)
	{
		write(STDOUT_FILENO, prompt, 6);
		char_read = getline(&lineptr, &n, stdin);
		if (char_read == -1)
		{
			perror("error");
			return (-1);
		}
		lineptr_cp = malloc(sizeof(char) *char_read);
		if (lineptr_cp == NULL)
		{
			perror("memory allocatio error");
			return (-1);
		}
		strcpy(lineptr_cp, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_token++;
			token = strtok(NULL, delim);
		}
		num_token++;
		argv = malloc(sizeof(char *) * num_token);
		token = strtok(lineptr_cp, delim);
		for (k = 0; token != NULL; k++)
		{
			argv[k] = malloc(sizeof(char) *  strlen(token));
			strcpy(argv[k], token);
			token = strtok(NULL, delim);
		}
		argv[k] = NULL;
		execmd(argv);
	}
	free(lineptr_cp);
	free(lineptr);
	return (0);
}

