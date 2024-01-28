#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>
#include <unistd.h>

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
return (0);
}

while (*ptr)
{
if (*ptr != '%')
{
write(1, ptr, 1);
count++;
}
else
{
switch (*(++ptr))
{
	case 'c':
	{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	count++;
	break;
	}
	case 's':
	{
	const char *str = va_arg(args, const char *);

	while (*str)
	{
	write(1, str, 1);
	count++;
	str++;
	}
	break;
	}
	case '%':
	{
	write(1, "%", 1);
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
