#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
* _printf - check the code
* description: the progrogram is basically printf function
* @format: the main string
* @...: the vars to use on the specifiers
* Return: the count of lenght.
*/


int _printf(const char *format, ...)
{

int count = 0;

const char *ptr = format;

va_list args;
va_start(args, format);

if (format == NULL)
{
return (-1);
}

while (*ptr)
{
if (*ptr != '%')
{
_putchar(*ptr);
count++;
}
else
{
if (*(ptr + 1) == '\0')
{
return -1;
}
switch (*(++ptr))
{
	case 'c':
	{
	char c = (char)va_arg(args, int);

	_putchar(c);
	count++;
	break;
	}
	case 's':
	{
	const char *str = va_arg(args, const char *);

	if (str == NULL) {
	str = "(null)";
	}
	while (*str)
	{
	_putchar(*str);
	count++;
	str++;
	}
	break;
	}
	case '%':
	{
	_putchar(37);
	count++;
	break;
	}
	
case 'i':
{
    int n = va_arg(args, int);
    char temp_buffer[12]; // Maximum 12 characters for a 32-bit integer, including the sign and null terminator
    int printed = 0;

    if (n < 0) {
        _putchar('-');
        printed++;
        n = -n;
    }
    if (n == 0) {
        _putchar('0');
        printed++;
    }
    else {
        int index = 0;
        while (n != 0) {
            temp_buffer[index++] = (char)((n % 10) + '0');
            n /= 10;
        }
        while (index > 0) {
            _putchar(temp_buffer[--index]);
            printed++;
        }
    }
    count += printed;
    break;
}


	default:
    _putchar('%');
    _putchar(*ptr);
    count += 2;
    break;
	
}
}
ptr++;
}
va_end(args);
return (count);
}
