#include "simple_shell.h"
/**
* alias_builtin - Implements the alias builtin command
* @args: An array of strings containing the command and its arguments
*
* Return: Always returns 0
*/
int alias_builtin(char **args)
{
/* Check if the command has enough arguments */
if (args[1] == NULL || args[2] == NULL)
{
char *error_msg = "alias: missing arguments\n";
/* Print  error message if com does not have enough arguments */
write(STDERR_FILENO, error_msg, strlen(error_msg));
return (1);
}
/* am yet to implement alias functionality */
/* Return 0 to indicate that the command was successful */
return (0);
}
