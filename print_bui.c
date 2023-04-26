#include "main.h"
/**
 * print_inreverse
*/
int print_inreverse(int n)
{
	char c;
	int quo = 1;
	int rem;
	int l = 0;

	if (n)
	{
		quo = n / 2;
		rem = n % 2;
		l =+ print_inreverse(quo);
		c = rem + '0';
		if (rem == 1)
			l += write(1, &c, 1);
		if (rem == 0)
			l += write(1, &c, 1);
	}
	return (l);
}
/**
 * print_b -
*/
int print_bui(va_list  ap)
{
	unsigned int n = (unsigned int)va_arg(ap, int);
	char c; 

	if (n == 0)
	{
		c = '0';
		return (write(1, &c, 1));
	}
	if (n == UINT_MAX)
	{}
	if (n == UINT_MAX + 1024)
	{}
	if (n == UINT_MAX * 2)
	{}
	return (print_inreverse(n));
}
