#include "main.h"

/**
 * bfree - function frees a pointer and NULLs the address
 * @ptr: address of the pointer
 * Return: 1 if freed, 0 if not.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
