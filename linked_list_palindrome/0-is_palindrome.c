#include "lists.h"
#include <stdlib.h>

/**
 * reverse_list - Reverses a singly linked list
 * @head: Pointer to the head of the list
 * Return: New head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head;
    listint_t *first_half, *second_half;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return (1);

    /* Find the middle of the list */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse second half */
    second_half = reverse_list(slow);
    first_half = *head;

    /* Compare both halves */
    while (second_half)
    {
        if (first_half->n != second_half->n)
            return (0);
        first_half = first_half->next;
        second_half = second_half->next;
    }

    return (1);
}
