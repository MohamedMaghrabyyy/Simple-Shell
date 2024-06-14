#include "shell.h"
/**
 * findchar - findsout if a certain char exists in a string or not
 * @s: passed string
 * @c: char to search for
 *
 * Return: 1 (if exists) & 0 (if not exist)
 */
int findchar(const char *s, char c)
{
	ssize_t i;
	ssize_t len = _strlen(s);

	if (!s)
		return (0);
	for (i = 0; i < len; i++)
	{
		if (s[i] == c)
			return (1);
		continue;
	}
	return (0);
}
