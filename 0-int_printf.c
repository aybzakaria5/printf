#include "main.h"
/**
 * _strlen - Return the length of a string
 *@s: the string to calcullate its lenght
 *
 *Return: the lenght of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 *print_c - print a single character
 *@arg: the character argument
 *
 *Return: always 1
 */
int print_c(va_list arg)
{
	char c;

	c = (char) va_arg(arg, int);
	return (write(1, &c, 1));
}

/**
 *print_s - print a string
 *@arg: the string argument
 *
 *Return:  lenght of the string argument
 */
int print_s(va_list arg)
{
	char *s;

	s = va_arg(arg, char *);
	if (s == NULL)
		s = "(null)";
	write(1, s, _strlen(s));
	return (_strlen(s));
}
/**
 *print_switch - print charcater or string
 *@format: the string format
 *@ap: the argument list
 *@i: the format specifire
 *
 *Return: number of character printed
 */
int print_switch(const char *format, va_list ap, int i)
{
	int l = 0;

	switch (format[i + 1])
	{
		case '%':
			l += write(1, &format[i], 1);
			break;
		case 'c':
			l += print_c(ap);
			break;
		case 's':
			l += print_s(ap);
			break;
		case '\0':
		case ' ':
			return (-1);
		case 'i':
		case 'd':
			l += print_di(ap);
			i++;
			break;
		default:
			write(1, &format[i], 1);
			return (-2);
	}
	return (l);
}

/**
 *_printf - produces output according to a format
 *@format: the format string
 *
 *Return: number of character printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int l, i, count;

	va_start(ap, format);
	i = l = count = 0;
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count = print_switch(format, ap, i);
			if (count == -1)
				return (-1);
			if (count == -2)
				l++;
			if (count >= 0)
			{
				i++;
				l += count;
			}
		}
		else
			l += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (l);
}

