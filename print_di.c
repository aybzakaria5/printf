#include"main.h"
/**
 *print_di - afunction that returns how many of inputs
 *@arg: args
 *Return: returns how many of numbers printed
 */

int print_di(va_list arg)
{
	int n = va_arg(arg, int);
	int len = 0;
	char c;
	int much_digits = 0;
	int temp, digit, i;

	if (n < 0)
	{
		write(1, "-", 1);
		len++;
		n *= -1;
	}

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	temp = n;
	while (temp)
	{
		much_digits++;
		temp /= 10;
	}

	while (much_digits > 0)
	{
		int div = 1;

		for (i = 1; i < much_digits; i++)
			div *= 10;
		digit = n / div;
		c = digit + '0';

		write(1, &c, 1);
		len++;
		n -= digit * div;
		much_digits--;
	}
	return (len);
}
