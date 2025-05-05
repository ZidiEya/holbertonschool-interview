#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a string
 * @str: the string to scan
 * @pattern: the regex pattern
 *
 * Return: 1 if matches, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (!pattern || !str)
		return (0);

	/* If pattern is empty, match only if str is also empty */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Check if current characters match (or if pattern has .) */
	int first_match = (*str && (*pattern == *str || *pattern == '.'));

	/* Handle '*' wildcard: 2 possibilities */
	if (*(pattern + 1) == '*')
	{
		/* 
		 * Either we:
		 * 1. Skip "char*" in the pattern (zero occurrence) OR
		 * 2. Move str ahead if first chars match (consume one match)
		 */
		return (regex_match(str, pattern + 2) ||
				(first_match && regex_match(str + 1, pattern)));
	}
	else
	{
		/* No '*', so both str and pattern advance */
		return (first_match && regex_match(str + 1, pattern + 1));
	}
}
