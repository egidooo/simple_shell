#include "shell.h"
/**
 * main: boilerplate
 * @ac: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int ac, char **argv)
{
	char *prompt = "(Ehafsa) #", *token = 0;
	char *lineptr = NULL, *lineptr_cp = NULL;
	size_t n = 0;
	ssize_t chars_read;
	const char *delim = " \n";
	int k, tokens_num = 0;
	(void)ac;

	while (1)
	{
	printf("%s", prompt);
	chars_read = getline(&lineptr, &n, stdin);
	if (chars_read == -1)
	{
		printf("exit .");
		return (-1);
	}
	lineptr_cp = malloc(sizeof(char) * chars_read);
	if (lineptr_cp == NULL)
	{
		perror("memory allocation error");
		return (-1);
	}
	strcpy(lineptr_cp, lineptr);
	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		tokens_num++;
		token = strtok(NULL, delim);
	}
	tokens_num++;
	argv = malloc(sizeof(char *) * tokens_num);
	token = strtok(lineptr_cp, delim);
	for (k = 0; token != NULL; k++)
	{
		argv[k] = malloc(sizeof(char) * strlen(token));
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
