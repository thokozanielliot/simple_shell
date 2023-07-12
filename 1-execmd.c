#include "main.h"

/**
 * execmd - Execute command
 * @av: Arguement vector
 * @en: environment name
 *
 * Return: No return
 */
void execmd(char **av, const char *en)
{
	char *cmd = NULL;

	if (av)
	{
		cmd = av[0];
		if (execve(cmd, av, NULL) == -1)
			perror(en);
	}
}
