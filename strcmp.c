#include "shell.h"
/**
 * _strcmp - compares to strings
 * @s1: first string
 * @s2: second string
 * Return: 0 (if s1 & s2 are the same)
 * postive number (s1 is longer)
 * negative number (s2 is longer)
 */
int _strcmp(const char *s1, const char *s2)
{
	int i, j, bigger;
	int k, flag = 0;

	i = _strlen(s1);
	j = _strlen(s2);

	if (i > j)
	{
		bigger = i - j;
		return (bigger);
	}
	else if (j > i)
	{
		bigger = i - j;
		return (bigger);
	}
	else
	{
		for (k = 0; k < i; k++)
		{
			if (s1[k] == s2[k])
				continue;
			else
			{
				bigger = s1[k] - s2[k];
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0)
		return (0);
	else
		return (bigger);
}
