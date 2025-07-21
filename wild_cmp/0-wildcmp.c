#include "holberton.h"

/**
 * wildcmp - compares two strings with wildcard support
 * @s1: the first string
 * @s2: the second string (may contain the wildcard '*')
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		/* Skip multiple '*' */
		while (*s2 == '*')
			s2++;

		/* If wildcard is last, it's a match */
		if (*s2 == '\0')
			return (1);

		/* Recursively compare substrings */
		while (*s1)
		{
			if (wildcmp(s1, s2))
				return (1);
			s1++;
		}

		return (0);
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
