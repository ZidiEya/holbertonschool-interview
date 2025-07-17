#include "holberton.h"
#include <stdlib.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: the string to check
 *
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: the string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * print_error - prints "Error" and exits with status 98
 */
void print_error(void)
{
	char *msg = "Error\n";
	int i = 0;

	while (msg[i])
	{
		_putchar(msg[i]);
		i++;
	}
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, *result;
	int n1, n2, carry, sum, start;

	if (argc != 3)
		print_error();

	num1 = argv[1];
	num2 = argv[2];
	if (!is_digit(num1) || !is_digit(num2))
		print_error();

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result = malloc(sizeof(int) * (len1 + len2));
	if (result == NULL)
		exit(98);

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			result[i + j + 1] = sum % 10;
			carry = sum / 10;
		}
		result[i + j + 1] += carry;
	}

	start = 0;
	while (start < len1 + len2 && result[start] == 0)
		start++;
	if (start == len1 + len2)
		_putchar('0');
	else
	{
		for (i = start; i < len1 + len2; i++)
			_putchar(result[i] + '0');
	}
	_putchar('\n');
	free(result);
	return (0);
}

