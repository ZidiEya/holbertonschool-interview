#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - check if it is palindrome
 * @head: linked list
 * Return: 1or 0
 */
int is_palindrome(listint_t **head)
{
    listint_t *temp;
    int i = 0, j = 0, even_or_odd = 0;
    int num_array[10000];

    if (!*head)
        return (1);

    temp = *head;
    while (temp)
    {
        num_array[i] = temp->n;
        i++;
        temp = temp->next;
    }
    i--;
    if (i == 0)
        return (1);
    even_or_odd = (i % 2 == 0) ? 2 : 1;

    for (; j <= i; i--, j++)
    {
        if (num_array[j] != num_array[i])
            return (0);
        else if (j == i - even_or_odd)
            return (1);
    }
    return (0);
}
