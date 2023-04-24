#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
/**
 *_printf - function prototype
 * Description: produces output according to a format.
 * @format: last argument
 * Return: num
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *str;
	char c;
	int num = 0;

	va_start(args, format);

	while (*format)
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				num++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, const char *);
				num += printf("%s", str);
			}
			else if (*format == '%')
			{
				putchar('%');
				num++;
			}
		}
		else
		{
			putchar(*format);
			num++;
		}

	va_end(args);

	return (num);
}
