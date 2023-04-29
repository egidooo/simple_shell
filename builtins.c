#include "shell.h"
/**
 * _myexit - function exits the shell
 * @info: structure
 * Return: exit with a given exit ststus
 */

int _myexit(ino_t *info)
{
	int check;

	if (info->argv[1])
	{
		check = _erratoi(info->argv[1]);
		if (check == -1)
		{
			info->ststus = 2;
			print_error(info, "illigal number:");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * -mycd - change the current directory
 *  @info: structure
 *  Return: always 0
 */
int _mycd(info_t *ino_t)
{
	char *s, *direct, buffer[1024];
	int chdirect_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO:>>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		direct = _getenv(info, "HOME=");
		if (!direct)
			chdirect((direct = _getenv(info, "PWD=")) ? direct : ":");
		else
			chdirect = chdirect(direct);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD="));
		_putchar('\n');
		chdirect((dir = _getenv(info, "OLDPWD=")) ? direct : "/");
	}
	else 

		chdirect _ret = chdirect(info->argv[1]);
		if (chdirect_ret == -1)
		{
			print_error(info, "can not cd to");
			_eputs(info->argv[1]);
			_eputchar('\n');
		}
		else
		{
			_setenv(info, "OLDPWD", _getenv(info, "PWD="));
			_setenv(info, "PWD", getcwd(buffer,1024));
		}
		return (0);
}
/**
 * _myhelp - change the current working directory
 * @info: structure
 * Return: 0
 */
int _myhelp(ino_t *info)
{
	char **arg_array;

	arg_arry = info->argv;
	_puts("help call works. function implimention fails \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
