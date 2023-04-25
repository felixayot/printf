#include "main.h"
/**
 *_printf - function prototype(produces output according to a format.)
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
		*format == '%' ? (
			*++format == '\0' ? (
				va_end(args), -1
			) : (
				*format == 'c' ? (
					num++, putchar(va_arg(args, int))
				) : *format == 's' ? (
					num += printf("%s", va_arg(args, char *))
				) : *format == 'd' || *format == 'i' ? (
					num += printf("%d", va_arg(args, int))
				) : (
					num += printf("%c", *format), num++
				)
			)
		) : (
			num++, putchar(*format)
		);
		format++;
	}
	va_end(args);
	return (num);
}
