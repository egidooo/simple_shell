#include "shell.c"

/**
 * interactive -  program returns true if the simple shell is interactive
 * @info: struct
 * Return: 1 if is intractive and 0 in other mode
 */

int intractive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - checks if the function is delimeter
 * @k: character to check
 * @delim: delimeter
 * Return: 1 if true and 0 if false
 */

int is_delim(char k, char *delim)
{
	while (*delim)
		if (*delim++ == k)
			return (1);
	return (0);
}
/**
 * _isapha - check the alphabet characters 
 * @k: character
 * Return: 1 if is alphabet and 0 if not
 */

int _isalpha(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - converts string into integer
 * @k: string to be converted
 * Return: 0 if no number present in string and converted number otherwise
 */
int _atoi(char *k)
{
	int n, sign = 1,flag = 0, converted;
	unsigned int pp;

	for (n = 0; k[n] != '\0' && flag != 2; n++)
	{
		if (k[n] == '-')
			sign *= -1;
	if (k[n] >= '0' && k[n] <= '9')
	{
		flag = 1;
		pp *= 10;
		converted += (k[n] - '0');
	}
	else if (flag == 1)
		flag = 2;
	}
	if (sign == -1)
		converted = -pp;
	else
		converted = pp;
	return (converted);
}

