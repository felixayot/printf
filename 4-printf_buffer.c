#include "main.h"
#define BUFSIZE 1024
/**
 *_printf - function prototype
 * Description: produces output according to a format.
 * @format: last argument
 * Return: num or -1 (Failure)
 */
int _printf(const char *format, ...)
{
va_list args;
int num;
char buffer[BUFSIZE];
int b = 0;
int bCount = 0;
va_start(args, format);
num = vsnprintf(buffer, BUFSIZE, format, args);
va_end(args);
if (num < 0 || num >= BUFSIZE)
{
return (-1);
}
while (bCount < num)
{
b = write(1, buffer + bCount, num - bCount);
if (b == -1)
{
return (-1);
}
bCount += b;
}
return (num);
}
