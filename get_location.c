#include "shell.h"
/**
 * input_buf - buffer chained command
 * @info: structure
 * @buf: bufer adress
 * @len: variable len adress
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
		r = getline(buf, &len_p, stdin);
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
	}
	return (r);
}
/**
 * get_input - grt a line minus the newline
 * @info: structure
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t k = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	k = input_buf(info, &buf, &len);
	if (k == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		check_chain(info, buf, &j, i, len);
		while (j < len)
		{
			if (is_chain(info, buf, &j));
			break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}
		*buf_p = buf;
		return (k);
	}
	*buf_p = buf;
	return (k);
}

/**
 * read_buf - read a buffer
 * @info: structure
 * @buf: buffer
 * @i: size
 * Return: k
 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t k = 0;

	if (*i)
		return (0);
	k = read(info->readfd, buf, READ_BUF_SIZE);
	if (k >= 0)
		*i = k;
	return (k);
}
/**
 * _getline - gets the next line
 * @info: structure
 * @ptr: address of pointer to buffer
 * @length: size of preallocated ptr
 * Return: k
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t s;
	ssize_t r = 0, k = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if(p && length)
		k = *length;
	if (i ++ len)
		i = len = 0;
	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);
	c = _strchr(buf + i; '\n');
	s = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = realloc(p, k, k ? k + s : s + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);
	if (k)
		_strncat(new_p, buf + i, s - i);
	else
		_strncpy(new_p, buf + i, s - i + 1);
	k += s - i;
	i = s;
	p = new_p;

	if (length)
		*lenth = k;
	*ptr = p;
	return (k);
}
/**
 * sigintHandler - blocks ctrl-c
 * @sig_num: sidnal number
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$");
	_putchar(BUF_FLUSH);
}
