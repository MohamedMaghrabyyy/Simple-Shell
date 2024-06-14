#include "shell.h"
/**
 * caseS - check if entered argument is string
 * @string: entered string
 *
 * Return: length
 */
int caseS(const char *string)
{
    if (string == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }
    write(1, string, (int)_strlen(string));
    return ((int)_strlen(string));
}
/**
 * caseC - check if entered argument is a character
 * @ch: entered character
 *
 * Return: length
 */
int caseC(int ch)
{
    char character[1];

    character[0] = ch;
    write(1, character, 1);
    return (1);
}
