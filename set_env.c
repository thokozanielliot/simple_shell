#include "main.h"
/**
 * set_env - sets env
 * @args: arguments
 *
 * Return: 0 on success
 */
int set_env(char **args)
{
	char *text = "Error: Not enough args";
	char *sname, *value, *tmp;
	int m, find;

	if (!args[1] || !args[2])
	{
		write(2, text, _strlen(text));
		return (1);
	}
	sname = args[1];
	value = args[2];

	for (m = 0; environ[m]; m++)
	{
		tmp = strtok(environ[m], "=");
		if (_strcmp(tmp, sname))
		{
			find = 1;
			break;
		}
	}

	if (find)
	{
		environ[m] = malloc(_strlen(sname) + _strlen(value) + 2);
		if (!environ[m])
			return (1);
		tmp = str_concat(sname, "=");
		environ[m] = str_concat(tmp, value);
		free(tmp);
	}
	else
		new_env(m, sname, tmp, value);

	return (0);
}

