#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _printf(const char *format, ...);
int caseS(const char *string);
int caseC(int ch);
int casePercentage();
int caseD(int num);
int _putchar(char c);
void write_data();
int caseR(const char *string);
extern char **environ;
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
int _atoi(char *s);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_memset(char *s, char b, unsigned int n);
/*int unsetenv(char *name);*/
char *_getenv(const char *name);
int findchar(const char *s, char c);
int setenv(const char *name, const char *value, int overwrite);
#endif
