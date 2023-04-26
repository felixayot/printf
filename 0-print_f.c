#include "main.h"
#define BUFSIZE 1024
/**
 *_printf - function prototype
 * Description: produces output according to a format.
 * @format: last argument
 * Return: num
 */
int _printf(const char *format, ...)
{
	char buffer[BUFSIZE];
	va_list args;
	int num = 0;

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
					buffer[num++] = va_arg(args, int);
					break;
				case 's':
					num += sprintf(buffer + num, "%s", va_arg(args, char *));
					break;
				case '%':
					buffer[num++] = '%';
					break;
				case 'd':
				case 'i':
					num += sprintf(buffer + num, "%d", va_arg(args, int));
					break;
				case 'b':
					num += sprintf(buffer + num, "%u", va_arg(args, size_t));
					break;
				case 'u':
					num += sprintf(buffer + num, "%u", va_arg(args, size_t));
					break;
				case 'o':
					num += sprintf(buffer + num, "%o", va_arg(args, size_t));
					break;
				case 'x':
					num += sprintf(buffer + num, "%x", va_arg(args, size_t));
					break;
				case 'X':
					num += sprintf(buffer + num, "%X", va_arg(args, size_t));
					break;
				case 'p':
					num += sprintf(buffer + num, "%p", va_arg(args, void *));
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
			buffer[num++] = *format;
			num++;
		}
		format++;
	}
	va_end(args);
	write(1, buffer, num);
	return (num);
}
