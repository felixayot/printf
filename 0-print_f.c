#include "main.h"
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

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) == '\0')
			return (-1);

		if (*format == '%' && *(format + 1) == '%')
		{
			putchar('%');
			num++;
			format += 2;
			continue;
		}
		if (*format == '%')
		{
			format++;
			num += (*format == 'c') ? (putchar(va_arg(args, int)), num++, 0) :
				((*format == 's') && va_arg(args, char *)) ?
				(num += printf("%s", va_arg(args, char *))) :
				((*format == 'd') || (*format == 'i')) ?
				(num += printf("%d", va_arg(args, int))) :
				(putchar('%'), putchar(*format), num += 2);
		}
		else
		{
			putchar(*format), num++;
		}
		format++;
	}
	va_end(args);
	return (num);
}
