#ifndef _MAIN_H
#define _MAIN_H

#define MAX_BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/** External environment **/
extern char **environ;

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
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/** Execute command **/
void execmd(char **av, const char *en);

/** Get Path of command **/
char *get_path(char *cmd);
char *get_env(char *name);

/** Builtin functions **/
void exit_shell(char **argv);
void print_env(void);
int change_dir(const char *path);

#endif
