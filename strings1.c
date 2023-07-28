#include "main.h"

/**
 * _eputs - this prints the input string
 * @str: a string to be printed
 *
 * Return: Nothing , None
 */
void _eputs(char *str)
{
	int w = 0;

	if (!str)
		return;
	while (str[w] != '\0')
	{
		_eputchar(str[w]);
		w++;
	}
}

/**
 * _eputchar - this will write the character c to stderr
 * @c: a character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set incorrectly.
 */
int _eputchar(char c)
{
	static int w;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || w >= WRITE_BUF_SIZE)
	{
		write(2, buf, w);
		w = 0;
	}
	if (c != BUF_FLUSH)
		buf[w++] = c;
	return (1);
}

/**
 * _putfd - this will write the character c to  fd
 * @c: is the character to print
 * @fd: a filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set incorrectly.
 */
int _putfd(char c, int fd)
{
	static int w;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || w >= WRITE_BUF_SIZE)
	{
		write(fd, buf, w);
		w = 0;
	}
	if (c != BUF_FLUSH)
		buf[w++] = c;
	return (1);
}

/**
 * _putsfd - this will print an input string
 * @str: a string to be printed
 * @fd: a filedescriptor to write to
 *
 * Return: The number of chars put
 */
int _putsfd(char *str, int fd)
{
	int w = 0;

	if (!str)
		return (0);
	while (*str)
	{
		w += _putfd(*str++, fd);
	}
	return (w);
}
