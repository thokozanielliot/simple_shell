#include "main.h"

/**
 * main - Start shell loop
 * @ac: number of arguements
 * @av: arguement vector
 *
 * Return: 0 always
 */
int main(int ac, char **av)
{
	char *buffer = NULL, **argv;
	size_t len;
	ssize_t nread;
	int status = 0;
	pid_t child_pid;

	(void) ac, (void) av;
	while (1)
	{
		_puts("($) ");
		nread = getline(&buffer, &len, stdin);
		if (nread == -1)
		{
			_putchar('\n');
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		argv = parser(buffer);
		child_pid = fork();
		if (child_pid  == 0)
		{
			execmd(argv, av[0]);
			exit(0);
		}
		else
			wait(&status);
		free(argv);
	}
	return (0);
}

/**
 * byte_count - counts the number bytes given in the string
 *
 * @s: string to count
 * Return: number of bytes
 */
int byte_count(char *s)
{
	int status = 0, no = 0;

	while (*s)
	{
		if (*s == '\n' || *s == '\t' || *s == ' ' || *s == ':')
			status = 0;
		else if (status == 0)
		{
			status = 1;
			no++;
		}
		s++;
	}
	return (no);
}

/**
 * parser - tokenize string given using delimeter
 *
 * @str: string given
 * Return: pointer to strings split
 */
char **parser(char *str)
{
	char **av = NULL, *token;
	const char *delim = " \t\n";
	int i, no_bytes = byte_count(str);

	av = malloc(sizeof(av) * (no_bytes + 1));
	if (!av)
		return (NULL);
	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
	{
		av[i] = malloc(sizeof(token) * (_strlen(token) + 1));
		_strcpy(av[i], token);
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
	return (av);
}
