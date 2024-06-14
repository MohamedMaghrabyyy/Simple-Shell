#include "shell.h"
/**
 * _memset - fills n bytes of memory
 *
 * @s: pointer to start of memory area
 * @b: constant byte to fill with
 * @n: num bytes to fill in
 *
 * Return: pointer to beginning of memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;
	char *start = s;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (start);
}
