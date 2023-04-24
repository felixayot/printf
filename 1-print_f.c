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
int num = 0;
va_start(args, format);
num = vprintf(format, args);
va_end(args);
return (num);
}
