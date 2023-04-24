#include "shell.h"
/**
 * get_location: get the location of the given command
 * @command: command wtitten in the shell
 * Return: NULL
 */

char *get_location(char *command)
{
	int command_length, directory_length;
	char *path, *path_cp, *file_path, *path_token;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_cp = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_cp, ":");

		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_cp);
				return (file_path);
			}
				else
				{
					free(file_path);
					path_token = strtok(NULL, ":");
				}
		}
			free(path_cp);
			if (stat(command, &buffer) == 0)
			{
				return (command);
			}
			return (NULL);
	}
	return (NULL);
}
