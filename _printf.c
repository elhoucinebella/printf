#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>

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


while (*ptr)
{
if (*ptr != '%')
{
_putchar(*ptr);
count++;
}
else
{
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
}
}
ptr++;
}
va_end(args);
return (count);
}
