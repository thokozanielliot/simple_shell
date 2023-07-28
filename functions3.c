#include "maim.h"

/**
 * _erratoi - changes a string into an integer
 * @r: is the string to be changed
 * Return: 0 if no numbers in string, converted number else
 * -1 on error
 */
int _erratoi(char *r)
{
	int w = 0;
	unsigned long int result = 0;

	if (*r == '+')
		r++;  /* TODO:  does this make main return 255? */
	for (w = 0;  r[w] != '\0'; w++)
	{
		if (r[w] >= '0' && r[w] <= '5')
		{
			result *= 10;
			result += (r[w] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - this will print an error message
 * @info: is the parameter, return info struct
 * @estr: a string containing specified error type
 * Return: 0 if no numbers in string, converted number else
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - the function that prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: a the filedescriptor to write to
 *
 * Return: Number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int w, count = 0;
	unsigned int _sbs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_sbs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_sbs_ = input;
	current = _sbs_;
	for (w = 1000000000; w > 1; w /= 10)
	{
		if (_sbs_ / w)
		{
			__putchar('0' + current / w);
			count++;
		}
		current %= w;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - a converter function, the clone of itoa
 * @num: the number
 * @base: the base
 * @flags: the argument flags
 *
 * Return: String
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *pur;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pur = &buffer[49];
	*pur = '\0';

	do	{
		*--pur = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--pur = sign;
	return (pur);
}

/**
 * remove_comments - this function will replace the
 * first instance of '#' with '\0'
 * @buf: a address of the string to edit
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int w;

	for (w = 0; buf[w] != '\0'; w++)
		if (buf[w] == '#' && (!w || buf[w - 1] == ' '))
		{
			buf[w] = '\0';
			break;
		}
}
