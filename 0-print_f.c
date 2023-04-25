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
	while (*format)
	{
		if (!*format)
		{
			return (-1);
		}
		*format == '%' ? (
			*++format == '\0' ? (va_end(args), -1) :
			*format == 'c' ? (num++, putchar(va_arg(args, int))) :
			*format == 's' ? (num += printf("%s", va_arg(args, char *))) :
			*format == '%' ? (num++, putchar('%')) :
			*format == 'd' || *format == 'i' ?
			(num += printf("%d", va_arg(args, int))) :
			(putchar('%'), putchar(*format), num += 2), 0
		) : (putchar(*format), num++, 0), format++;
	}
	va_end(args);
	return (num);
}
