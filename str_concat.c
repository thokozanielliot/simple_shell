#include "main.h"
#include <stdio.h>
#include <stdlib.h>



/**
 * con_str - concatenate str
 * @str1: string 1
 * @str2: string 2
 * @p: pointer from malloc
 * @c1: s1 count
 * @c2: s2 count
 * Return: pointer from malloc
 */

char *con_str(char *str1, char *str2, char *p, int c1, int c2);

/**
 * str_concat - concatenate two strings
 * @str1: first string
 * @str2: second string
 * Return: pointer to string, or NULL if fail
 */

char *str_concat(char *str1, char *str2)
{
	char *p;
	int c1 = 0, c2 = 0;
	char n[1] = {'\0'};

	if (!str1)
		str1 = n;
	if (!str2)
		str2 = n;

	while (str1[c1])
		c1++;

	while (str2[c2])
		c2++;

	p = malloc(sizeof(char) * (c1 + c2) + 1);

	if (!p)
		return (NULL);

	return (con_str(str1, str2, p, c1, c2));
}

/**
 * con_str - concatinate str
 * @str1: string 1
 * @str2: string 2
 * @p: pointer from malloc
 * @c1: s1 count
 * @c2: s2 count
 * Return: pointer from malloc
 */

char *con_str(char *str1, char *str2, char *p, int c1, int c2)
{
	int m = 0, n = 0;

	while (str1[m])
	{
		p[m] = str1[m];
		m++;
	}

	while (str2[n])
	{
		p[c1 + n] = str2[n];
		n++;
	}
	p[c1 + c2] = '\0';

	return (p);
}
