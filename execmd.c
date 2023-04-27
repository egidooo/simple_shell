#include "shell.h"
/**
 * execmd - checks if the argv is not empty
 * @argv: argument
 * Return: void
 */

void execmd(char **argv)
{
	char *command = NULL, *real_command = NULL;

	if (argv)
	{
		command = argv[0];
		real_command = get_location(command);
		if (execve(real_command, argv, NULL) == -1)
		{
			perror("error");
		}
	}
}
