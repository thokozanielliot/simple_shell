#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/** Print function **/
int _putchar(char c);
void _puts(char *str);

/** Tokenize the input **/
char **parser(char *str);

/** Byte count **/
int byte_count(char *s);

/** String functions **/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

/** Execute command **/
void execmd(char **av, const char *en);

#endif
