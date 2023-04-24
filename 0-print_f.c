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
int len;
const char *str;
va_start(args, format);
while (*format != '\0')
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
str = va_arg(args, const char *);
len = printf("%s", str);
num += len;
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
