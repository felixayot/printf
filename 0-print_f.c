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
	int num = 0;
	const char *str;

	va_start(args, format);

	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
				break;
			format++;

			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					num++;
					break;
				case 's':
					num += printf("%s", va_arg(args, const char *));
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
	}
	va_end(args);

	return (num);
}
