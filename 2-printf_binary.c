#include "main.h"
/**
 * _printf - function prototype
 * Description: produces output according to a format.
 * @format: last argument
 * Return: 0 (Success)
 */
int _printf(const char *format, ...)
{
int a;
unsigned int num;
va_list args;
va_start(args, format);
for (; *format != '\0'; ++format)
{
if (*format == '%' && *(format + 1) == 'b')
{
num = va_arg(args, unsigned int);
for (a = 63; a >= 0; --a)
{
putchar((num >> a) & 1 ? '1' : '0');
}
format++;
}
else
{
putchar(*format);
}
}
va_end(args);
return (0);
}
