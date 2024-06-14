#include "shell.h"
/**
 * _strcpy - copies string in array src into buffer dest
 * @dest: buffer to copy into
 * @src: string to copy
 *
 * Return: copied string
 */
char *_strcpy(char *dest, const char *src)
{
	int count = 0;
	int i;

	while (1)
	{
		if (src[count] == '\0')
		{
			count++;
			break;
		}
		count++;
	}
	for (i = 0; i < count; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
