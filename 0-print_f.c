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
	int len;
	char *str;

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (-1);
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					num++;
					break;
				case 's':
					str = va_arg(args, char *);
					len = strlen(str);
					printf("%s", str);
					num += len;
					break;
				case '%':
					putchar('%');
					num++;
					break;
				case 'd':
				case 'i':
					num += printf("%d", va_arg(args, int));
					break;
				case 'u':
					num += printf("%u", va_arg(args, unsigned int));
					break;
				case 'o':
					num += printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					num += printf("%x", va_arg(args, unsigned int));
					break;
				case 'X':
					num += printf("%X", va_arg(args, unsigned int));
					break;
				case 'p':
					num += printf("%p", va_arg(args, void *));
					break;
				default:
					putchar('%');
					putchar(*format);
					num += 2;
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
