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

va_start(args, format);
while (*format != '\0')
{
if (*format == 'c')
{
char arg = va_arg(args, int);
putchar(arg);
num++;
}
else if (*format == 's')
{
char *arg = va_arg(args, char *);
printf("%s", arg);
num += strlen(arg);
}
else if(*format == '%')
{
putchar('%');
num++;
}
num++;
}
va_end(args);

return (num);
}
