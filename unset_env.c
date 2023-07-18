#include "main.h"

/**
 * unset_env - unsets env
 * @args: arguments
 *
 * Return: 1 on failure 0 on success
 */
int unset_env(char **args)
{
	char *text = "Usage: unsetenv VARIABLE\n";
	int final;

	if (!args[1])
	{
		if (!args[1])
			write(2, text, _strlen(text));
		return (1);
	}
	else
	{
		final = unsetenv(args[1]);
		if (!final)
			perror("unsetenv");
		return (1);
	}

	return (0);
}
