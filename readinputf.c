#include "main.h"

/**
 * input_buf - buffers are chained commands
 * @info: a parameter of struct
 * @buf: the place of the buffer
 * @len: the place of the len var
 *
 * Return: Bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t s = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing theres left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		s = getline(buf, &len_p, stdin);
#else
		s = _getline(info, buf, &len_p);
#endif
		if (s > 0)
		{
			if ((*buf)[s - 1] == '\n')
			{
				(*buf)[s - 1] = '\0'; /* delete the trailing newline */
				s--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) could this be a command chain? */
			{
				*len = s;
				info->cmd_buf = buf;
			}
		}
	}
	return (s);
}

/**
 * get_input - will get a line and minus the newline
 * @info: a parameter of struct
 *
 * Return: Bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t w, v, len;
	ssize_t s = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	s = input_buf(info, &buf, &len);
	if (s == -1) /* EOF */
		return (-1);
	if (len) /* some commands left in the chain buffer */
	{
		v = w; /* init a iterator in current buf position */
		p = buf + w; /* get a pointer to return */

		check_chain(info, buf, &v, w, len);
		while (v < len) /* iterate to a semicolon or end */
		{
			if (is_chain(info, buf, &v))
				break;
			v++;
		}

		w = v + 1; /* the increment past nulled ';'' */
		if (w >= len) /* end of buffer reached? */
		{
			w = len = 0; /* reset the position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back the pointer to the recent command position */
		return (_strlen(p)); /* return the length of recent command */
	}

	*buf_p = buf; /* else if not a chain, pass back buffer from _getline() */
	return (s); /* return the length of buffer from _getline() */
}

/**
 * read_buf - will read a buffer
 * @info: the parameter of struct
 * @buf: the buffer
 * @w: the size
 *
 * Return: s
 */
ssize_t read_buf(info_t *info, char *buf, size_t *w)
{
	ssize_t s = 0;

	if (*w)
		return (0);
	s = read(info->readfd, buf, READ_BUF_SIZE);
	if (s >= 0)
		*w = s;
	return (s);
}

/**
 * _getline - will get the next line to input from STDIN
 * @info: the parameter of struct
 * @ptr: the place of pointer to a buffer, preallocated or NULL
 * @length: the size of preallocated ptr buffer if not NULL
 *
 * Return: r
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t w, len;
	size_t y;
	ssize_t u = 0, r = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		u = *length;
	if (w == len)
		w = len = 0;

	u = read_buf(info, buf, &len);
	if (u == -1 || (u == 0 && len == 0))
		return (-1);

	c = _strchr(buf + w, '\n');
	y = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, r, r ? r + y : y + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (r)
		_strncat(new_p, buf + w, y - w);
	else
		_strncpy(new_p, buf + w, y - w + 1);

	r += y - w;
	w = y;
	p = new_p;

	if (length)
		*length = r;
	*ptr = p;
	return (r);
}

/**
 * sigintHandler - this blocks ctrl-C
 * @sig_num: is the signal number
 *
 * Return: Void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
