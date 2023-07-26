#include "main.h"

/**
 * _putchar - writes the character c to the stdout
 * @c: the character to print
 *
 * Return: On success 1
 * On error, -1 is returned, and errno is set apppropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @str: input string
 * Return: no return
 */
void _puts(char *str)
{
	int m = 0;

	for ( ; str[m]; m++)
	{
		_putchar(str[m]);
	}
}

/**
 * free_malloc - free allocated memory
 *
 * @str: string
 * Return: no return
 */
void free_malloc(char **str)
{
	char **mem = str;

	if (!str)
		return;
	while (*str)
		free(*str++);
	free(mem);
}
