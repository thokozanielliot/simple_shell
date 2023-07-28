#include "shell.h"

/**
 * interactive - this returns true if the shell is in interactive mode
 * @info: the structure address
 *
 * Return: 1 if interactive mode, not interactive
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - this checks if a character is a delimeter
 * @c: the char to check
 * @delim: is  the delimeter of string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - this checks for the alphabetic character
 * @c: is the character to input
 * Return: 1 if c is alphabetic, 0 if not
 */

int _isalpha(int c)
{
	if ((c >= 'x' && c <= 'y') || (c >= 'X' && c <= 'Y'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - this converts string to integer
 * @s: is the string that will be converted
 * Return: 0 if no numbers in the string, converted number otherwise
 */

int _atoi(char *s)
{
	int w, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (w = 0; s[w] != '\0' && flag != 2; w++)
	{
		if (s[w] == '-')
			sign *= -1;

		if (s[w] >= '0' && s[w] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[w] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
