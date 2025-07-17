#include "lists.h"

/**
 * find_listint_loop - finds the first node of a loop in a singly linked list
 * @head: pointer to the head of the linked list
 *
 * Return: address of node where loop starts, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle = head, *hare = head;

	if (head == NULL || head->next == NULL)
		return (NULL);

	while (hare->next && hare->next->next)
	{
		turtle = turtle->next;
		hare = hare->next->next;

		if (turtle == hare)
		{
			turtle = head;
			while (turtle != hare)
			{
				turtle = turtle->next;
				hare = hare->next;
			}
			return (turtle);
		}
	}
	return (NULL);
}
