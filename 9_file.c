#include "shell.h"

/**
 * read_line - Reads user input.
 * @i_eof: return value of end of line
 * Return: string
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
