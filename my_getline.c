#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * no_line - checks for not line prints error
 * @line: string to be checked
 */
void no_line(char *line)
{
	if (!line)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
}
/**
 * read_buffer - reads into data
 * @fd: file descriptor
 * Return: read_chars
 */
char *read_buffer(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int seen_chars;

	seen_chars = 0;

	seen_chars = read(fd, buffer, BUFFER_SIZE);
	if (seen_chars < 0)
	{
		perror("read error");
		exit(EXIT_FAILURE);
	}
	return (strndup(buffer, seen_chars));
}
/**
 * own_getline - reads an entire line
 * @fd: file descriptor
 * Return: the read line
 */
char *own_getline(int fd)
{
	static char *buffer;
	static int pos_buffer,  size_buffer;
	int pos_line = 0, size_line = BUFFER_SIZE;
	char *line = NULL, c;

	buffer = NULL;
	pos_buffer = 0;
	size_buffer = 0;
	while (1)
	{
		if (pos_buffer >= size_buffer)
		{
			free(buffer);
			buffer = read_buffer(fd);
			size_buffer = strlen(buffer);
			pos_buffer = 0;
		}
		c = buffer[pos_buffer++];
		if (c == '\n')
		{
			line[pos_line] = '\0';
			return (line);
		}
		line[pos_line++] = c;
		if (pos_line >= size_line)
		{
			size_line += BUFFER_SIZE;
			line = realloc(line, size_line);
			no_line(line);
		}
		if (!line)
		{
			line = malloc(size_line);
			no_line(line);
		}
	}
}
