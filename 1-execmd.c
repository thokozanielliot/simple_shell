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
	char *cmd = NULL, *act_cmd = NULL;

	if (av)
	{
		cmd = av[0];
		act_cmd = get_path(cmd);
		if (execve(act_cmd, av, environ) == -1)
			perror(en);
	}
}

/**
 * get_path - Gets path of a command
 * @cmd: Command to search
 *
 * Return: Pointer to command
 */
char *get_path(char *cmd)
{
	char *path, *path_copy, *path_tok, *file_path;
	int cmd_len, dir_len;
	struct stat buffer;

	path = get_env("PATH");
	if (path)
	{
		path_copy = strdup(path);
		cmd_len = _strlen(cmd);
		path_tok = strtok(path_copy, ":");
		while (path_tok != NULL)
		{
			dir_len = _strlen(path_tok);
			file_path = malloc(cmd_len + dir_len + 2);
			_strcpy(file_path, path_tok);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);
			_strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_tok = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(cmd, &buffer) == 0)
			return (cmd);
		return (NULL);
	}
	free(path);
	return (NULL);
}

/**
 * get_env -Get environment variable
 * @name: name of environment
 *
 * Return: Environment ponter
 */
char *get_env(char *name)
{
	size_t size = _strlen(name);
	char *env = NULL;
	int i = 0;

	while (environ[i])
	{
		if (!_strncmp(name, environ[i], size))
			env = environ[i] + size + 1;
		i++;
	}
	return (env);
}

/**
 * change_dir - change directory
 * @path: Path 
 *
 * Return: 0 on SUCCESS
 */
int change_dir(const char *path)
{
	char cwd[MAX_BUFFER_SIZE], *o_dir;

	o_dir = getenv("OLDPWD");
	if (o_dir == NULL)
	{
		fprintf(stderr, "cd: OLDPWD not set \n");
		return (-1);
		if (chdir(o_dir) != 0)
		{
			perror("cd: ");
			return (-1);
		}
		fprintf(stderr, "%s\n", o_dir);
	}
	else
	{
		if (chdir(path) != 0)
		{
			perror("cd: ");
			return (-1);
		}
		fprintf(stderr, "%s\n", getcwd(cwd, sizeof(cwd)));
	}
	setenv("PWD", getcwd(cwd, sizeof(cwd)), 1);
	return (0);
}
