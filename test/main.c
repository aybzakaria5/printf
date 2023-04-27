#include "main.h"
#include <stdio.h>
#include <limits.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len1, len2;

	len1 = printf("0");
	printf("\n");
	len2 = _printf("%b", 1);
	printf("\n-------------------\n");
	printf("%d, %d\n", len1, len2);

	return (0);
}
