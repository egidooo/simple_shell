#include "shell.h"

/**
 * execmd - execute the program reffered to pathname
 * @argv: argument vector
 * Return: void
 */

void execmd(char **argv)
{
	char *comm = NULL;

	if (argv)
	{
		comm = argv[0];
		if (execve(comm, argv, NULL) == -1)
		{
			perror("error:");
		}
	}
}
