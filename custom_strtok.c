#include "main.h"

/**
 * many_deli - checks continous delimeters
 * @follow_token: token to be checked
 * @delimeter: delimeters
 *
 * Return: 1 always successful
 */
int many_deli(char **follow_token, const char *delimeter)
{
	int scan = 0, m;

	while (**follow_token)
	{
		scan = 0;
		for (m = 0; delimeter[m] && **follow_token; m++)
		{
			if (**follow_token == delimeter[m])
			{
				**follow_token = '\0';
				(*follow_token)++;
				scan = 1;
			}
		}
		if (!scan)
			return (1);
	}
	return (1);
}

/**
 * _strtok - custom strtok
 * @str: string to be tokenized
 * @delimeter: delimeters
 *
 * Return: pointer to new token
 */
char *_strtok(char *str, const char *delimeter)
{
	static char *follow_token;
	char *first_token;
	int find_deli, m;

	if (str)
		follow_token = str;
	else if (!follow_token || !(*follow_token))
		return (NULL);
	many_deli(&follow_token, delimeter);
	first_token = follow_token;
	find_deli = 0;
	while (*follow_token)
	{
		for (m = 0; delimeter[m]; m++)
		{
			if (*follow_token == delimeter[m])
			{
				*follow_token = '\0';
				follow_token++;
				many_deli(&follow_token, delimeter);
				find_deli = 1;
				break;
			}
		}

		if (find_deli)
			break;
		follow_token++;
	}

	if (!first_token || !follow_token)
		return (NULL);
	return (first_token);
}
