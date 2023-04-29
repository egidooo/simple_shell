#include "shell.h"
/**
 * _strncp - copies string
 * @dest: destination of the string
 * @src: source string
 * @n: amount of character to be copied
 * Return: to the string being concatenated
 */

char *_strncp(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}
/**
 * _strncat - concatenates two string
 * @dest: first string
 * @src: second string
 * @n: amount of bytes
 * Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}
/**
 * _strchar - locates character in string
 * @s: string to be passed
 * @k: string to be looked
 * Return: pointer to the memeory
 */
char *_strchr(char *s, char k)
{
	do {
		if (*s == k)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}
