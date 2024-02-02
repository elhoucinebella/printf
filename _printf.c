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
    int printed = 0;

    if (n < 0)
    {
    _putchar('-');
    count++;
    n = -n;
    }
    if (n == 0)
    {
    _putchar('0');
    count++;
    }
    else
    {
    int temp = n;
    int num_chars = 0;
	char *num_str = malloc(num_chars + 1);
    while (temp != 0)
    {
	temp /= 10;
	num_chars++;
	}

	if (num_str == NULL)
	{	
    return -1;
	}

	num_str[num_chars] = '\0';
	while (n != 0)
	{
	num_str[--num_chars] = (char)((n % 10) + '0');
    n /= 10;
    }
    while (*num_str)
    {
    _putchar(*num_str);
    count++;
    num_str++;
    printed++;
    }
	free(num_str - printed);
    }
    break;
	default:
    _putchar('%');
    _putchar(*ptr);
    count += 2;
    break;
	}
}
}
ptr++;
}
va_end(args);
return (count);
}
