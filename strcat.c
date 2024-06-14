#include "shell.h"
/**
 * _strcat - same as strcat()
 * @dest: destination
 * @src: source
 *
 * Return: strings concatenated
 */
char *_strcat(char *dest, const char *src)
{
	int countDest = 0;
	int countSrc = 0;

	while (*(dest + countDest) != '\0')
	{
		countDest++;
	}

	while (*(src + countSrc) != '\0')
	{
		*(dest + countDest) = *(src + countSrc);
		countDest++;
		countSrc++;
		if (*(src + countSrc) == '\0')
		{
			*(dest + countDest) = '\0';
			break;
		}
	}

	return (dest);
}
