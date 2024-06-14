#include "shell.h"
/**
 * caseR - prints reversed string
 * @string: string
 *
 * Return: length
 */
int caseR(const char *string)
{
    int i, length, j;
    char *reverse;

    if (string == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }

    length = (int)_strlen(string);
    j = length - 1;
    reverse = malloc(sizeof(char) * (length + 1));
    if (reverse == NULL)
    {
        free(reverse);
        exit(98);
    }
    for (i = 0; i < length; i++)
    {
        reverse[i] = string[j];
        j--;
    }
    reverse[length] = '\0';
    write(1, reverse, length);
    free(reverse);
    return (length);
}
