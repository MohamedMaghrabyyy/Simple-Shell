#include "shell.h"
/**
 * _strlen - returns length of a string
 * @s: String required to get its length
 *
 * Return: number of characters in a string
 */
int _strlen(const char *s)
{
	int i = 0;
	int count = 0;

	while (s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}
