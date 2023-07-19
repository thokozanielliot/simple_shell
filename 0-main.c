#include "main.h"

/**
 * main - Start shell loop
 * @ac: number of arguements
 * @av: arguement vector
 *
 * Return: 0 always
 */
int c;
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
		exit_shell(argv);
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
 * exit_shell - Exits the shell loop
 * @argv: arguement vector
 *
 * Return: No return
 */
void exit_shell(char **argv)
{

	if (_strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(argv[0], "env") == 0)
		print_env();
	if (_strcmp(argv[0], "cd") == 0)
		change_dir(argv[1]);
	/**{
		child_pid = fork();
		if (child_pid == 0)
		{
			change_dir(argv[1]);
			exit(0);
		}
		c = 1;
	}**/
	if (_strcmp(argv[0], "setenv") == 0)
		set_env(argv);
	if (_strcmp(argv[0], "unsetenv") == 0)
		unset_env(argv);
}

/**
 * print_env - Print environment
 *
 * Return: No return
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
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
