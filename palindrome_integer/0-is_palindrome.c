#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned long integer is a palindrome
 * @n: The number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long r, sum = 0, temp;

	temp = n;
	while (n > 0)
	{
		r = n % 10;
		sum = (sum * 10) + r;
		n = n / 10;
	}

	if (temp == sum)
		return (1);
	return (0);
}
