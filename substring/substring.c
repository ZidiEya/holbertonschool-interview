#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * substring - extracts a substring from a string
 * @str: original string
 * @start: starting index
 * @len: length of substring
 * Return: pointer to substring
 */
char *substring(const char *str, int start, int len)
{
    char *sub;

    if (!str || start < 0 || len < 0 || start + len > strlen(str))
        return NULL;

    sub = malloc(len + 1);
    if (!sub)
        return NULL;

    strncpy(sub, str + start, len);
    sub[len] = '\0';

    return sub;
}
