#include "shell.h"
/**
 * _printf - printf() replica
 * @format: string to be printed
 *
 * Return: length of string printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char ch[1];
	int i = 0, length = 0;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					length += caseC(va_arg(ap, int));
					break;
				case 's':
				case 'S':
					length += caseS(va_arg(ap, char*));
					break;
				case '%':
					length += casePercentage();
					break;
				case 'd':
				case 'i':
					length += caseD(va_arg(ap, int));
					break;
				case 'r':
					length += caseR(va_arg(ap, char*));
					break;
				default:
					exit(98);
					break;
			}
			i++;
		}
		else
		{
			ch[0] = format[i];
			write(1, ch, 1);
			length++;
		}
		i++;
	}
	va_end(ap);
	return (length);
}
