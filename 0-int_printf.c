#include "main.h"

/**
 * _strlen - Return the length of a string
 * @s: The string to calculate its length
 *
 * Return: The length of the the string
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
 * print_c - print a single character
 * @arg: the character argument
*/
void print_c(va_list arg)
{
	char c;

	c = (char) va_arg(arg, int);
	write(1, &c, 1);
}

/**
 * print_s - print a string
 * @arg: the string argument
 *
 * Return: length of the string argument
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
 * print_cs - print character or string
 * @format: the string format
 * @ap: the argumant list
 *
 * Return: number of character printed
*/
int print_cs(const char *format, va_list ap)
{
	int l, i;

	i = l = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case '%':
				write(1, &format[i], 1);
				l++;
				i++;
				break;
			case 'c':
				print_c(ap);
				l++;
				i++;
				break;
			case 's':
				l += print_s(ap);
				i++;
				break;
			case 'i':
			case 'd':
				l += print_di(ap);
				i++;
				break;
			case '\0':
			case ' ':
				return (-1);
			default:
				write(1, &format[i], 1);
				l++;
				break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			l++;
		}
		i++;
	}
	return (l);
}
/**
 * _printf - produces output according to a format
 * @format: the format string
 *
 * Return: number of character printed
*/
int _printf(const char *format, ...)
{
	va_list ap;
	int l;

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	l = print_cs(format, ap);
	va_end(ap);
	return (l);
}
