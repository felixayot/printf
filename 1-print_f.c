#include "main.h"
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
const char *p;
int count = 0;
int num;
va_start(args, format);
for (p = format; *p; ++p)
{
if (*p == '%')
{
switch (*(++p))
{
case 'd':
case 'i':
{
num = va_arg(args, int);
fprintf(stdout, "%d", num);
++count;
break;
}
default:
fputc(*p, stdout);
++count;
break;
}
}
else
{
fputc(*p, stdout);
++count;
}
}
va_end(args);
return (count);
}
