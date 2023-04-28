#include <shell.h>

/**
 * _progress - display command by line and proceed starting from 0
 * @info: structure
 * Return: 0
 */
int _progress(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - unset alias to the string
 * @info: structure
 * @str: the string
 * Return: 1 if it fails and 0 success
 */

int unset_alias(info_t *info, char *str)
{
	char *k, i;
	int c;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	i = *k;
	*k = 0;
	c = delete_node_at_index(&(info->alias), get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*k = i;
	return (c);
}
/**
 * set_alias - set alias to the string
 * @info: structure
 * @str: the string
 * Return: 1 if it fails and 0 success
 */
int set_alias(info_t *info, char *str)
{
	char *k;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	if (!++k)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias) str, 0) == NULL);
}
/**
 * print_alias - print the alias string
 * @node: node of the alias
 * Return: 1 on error and 0 on success
 */
int print_alias(list_t *node)
{
	char *k = NULL, *n = NULL;

	if (node)
	{
		k = _strch(node->str, '=');
		for (n = node->str; n <= k; n++)
			_putchar(*n);
		_putchar('\');
		_puts(k + 1);
		_puts("\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - mimics the alias builtin
 * @info: structure
 * Return: always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *k = NULL;
	list_t *node = NULL;
	
	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->alias;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		k = _strchr(info->argv[i], '=');
		if (k)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_start_with(info->alias, info->argv[i], '='));
	}
	return (0);
}
