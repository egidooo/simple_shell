#include "shell.h"

/**
 * _eputs - prints the string
 * @str:the string to be printed
 * Return: void
 */

void _eputs(char *str)
{
	int i;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}
/**
 * _eputchar - writes the characker k into stderr
 * @k: character
 * Return: 1 success and -1 on error
 */

int _eputchar(char k)
{
	static int i;
	static char buf[1024];

	if (k == BUF_FLUSH || i >= 1024)
	{
		write(2, buf, i);
		i = 0;
	}
	if (k != BUF_FLUSH)
		buf[i++] = k;
	return (1);
}
/**
 * _putsfd - prints input string
 * @str: string to be printed
 * @fd: file discriptor
 * Return: number of character input
 */

int _putsfd(char *str, int fd)
{
	int i;

	if (!str)
		return (0);
	while (*str)
	{
		i+= _putfd(*str++, fd);
	}
	return (1);
}
