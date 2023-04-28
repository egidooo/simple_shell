#include "shell.c"
/**
 * _myenv - print the current environment
 * @info: structure
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return(0);
}
/**
 * _getenv - get value of environment
 * @info: structure
 * @name: name of the environment
 * Return: the value
 */
char*_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *k;
	
	while (node)
	{
		k = start_with(node->str, name);
		if (k && *k)
			return (k);
		node = node->next;
	}
	return (0);
}
/**
 * _mysetenv - set the new environment
 * or modify the existing one 
 * @info: structure
 * Return: 0
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("argument number is wrong");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - remove environment variable
 * @info: structure
 * Return: 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("arguments are few.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);
	return (0);
}
/**
 * populate_env_list - populate the linked list environment
 * @info: structure
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	aize_t i;
	for (i = 0; env[i]; i++)
		add_node_end(&node, env[i], 0);
	info->env = node;
	return (0);
}
