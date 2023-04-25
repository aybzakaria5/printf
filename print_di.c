#include"main.h"
/**
 *print_di - afunction that returns how many of inputs
 *@n: the inputs
 *Return: returns how many of numbers printed
 */

int print_di(int n)
{
	int len = 0;
	int i;
	int much_digits = 0;
	int temp = n;

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

	while (tmp)
	{
		much_digits++;
		tmp /= 10;
	}

	while (much_digits > 0)
	{
		int div = 1;

		for (i = 1; i < much_digits; i++)
			div *= 10;
		int digit = n / div;
		char c = digit + '0';

		write(1, &c, 1);
		len++;
		n -= digit * div;
		much_digits--;
	}
	return (len);
}
