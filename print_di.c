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
	int much_digits = 0;
	char c;
	int temp, digit, i;

	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = (long)n *  (-1);
	}
		if (n == 0)
		return (write(1, "0", 1));
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
