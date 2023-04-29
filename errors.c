#include "shell.h"
/**
 * _erratoi - converts string to integer
 * @s: string to be converted
 * Return: 0 if no number and converted number otherwise
 * -1 0n error
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int converted = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			converted *= 10;
			converted += (s[i] - '0');
			if (converted > INT_MAX)
				return (-1);
		}

		else
			return (-1);
	}
	return (converted);
}
/**
 * print_error - print the error
 * @info: structure
 * @estr: string
 * Return: 0 if no number,converted number otherwise
 * and -1 on errors
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
 * print_d - print decimal numbers
 * @input: the input
 * @fd: file discripter
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == DTDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	cuurrent = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current % = i;
	}
	__putchar('0' + current);
	count++;
	return (count);
}
/**
 * convert_number - convert function
 * @num: number
 * @base: base
 * @flags: flags
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *arry;
	static char bufffer[50];
	char sign = 0;
	char *ptr;
	unsigned long k = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		k = -num;
		sign = '-';
	}
	arry = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = arry[k % base];
		k /= base;
	}
	while (k != 0)
		if (sign)
			*--ptr = sign;
	return (ptr);
}
/**
 * remove_comment - replaces # with '\0'
 * @buff: adress of string
 * Return: 0
 */
void remove_comment(char *buff)
{
	int j;

	for (j = 0; buff[j] != '\0'; j++)
		if (buff[j] == '#' && (!j || buff[j - 1] == ' '))
		{
			buff[j] = '\0';
			break;
		}
}
