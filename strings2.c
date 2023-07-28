#include "main.h"

/**
 **_strncpy - clones, copies a string
 *@dest: this is the destination of
 *string to be copied, cloned to
 *@src: source of the string
 *@n: an amount of characters to be copied, cloned
 *Return: The concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int w, v;
	char *s = dest;

	w = 0;
	while (src[w] != '\0' && w < n - 1)
	{
		dest[w] = src[w];
		w++;
	}
	if (w < n)
	{
		v = w;
		while (v < n)
		{
			dest[v] = '\0';
			v++;
		}
	}
	return (s);
}

/**
 **_strncat - this will concatenates the two strings
 *@dest: is first string
 *@src: is second string
 *@n: a amount of bytes that will be maximally used
 *Return: the concatenated of string
 */
char *_strncat(char *dest, char *src, int n)
{
	int w, v;
	char *s = dest;

	w = 0;
	v = 0;
	while (dest[w] != '\0')
		w++;
	while (src[v] != '\0' && v < n)
	{
		dest[w] = src[v];
		w++;
		v++;
	}
	if (v < n)
		dest[w] = '\0';
	return (s);
}

/**
 **_strchr - will locate a character inside a string
 *@s: is the string that will be parsed
 *@a: is character to be look for
 *Return: (s) A pointer to the memory area s
 */
char *_strchr(char *s, char a)
{

	do {
		if (*s == a)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
