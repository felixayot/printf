#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 *_printf - function prototype
 * Description: produces output according to a format.
 * @format: last argument
 * Return: num
 */
int _printf(const char *format, ...)
{
	va_list args;
	int num = 0;

	if (!format && !'c' && 's' && '%')
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					num++;
					break;
				case 's':
					num += printf("%s", va_arg(args, char *));
					break;
				case '%':
					putchar('%');
					num++;
					break;
				default:
					break;
			}
		}
		else
		{
			putchar(*format);
			num++;
		}
		format++;
	}
	va_end(args);

	return (num);
}
