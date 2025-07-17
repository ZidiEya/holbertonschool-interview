#include "lists.h"

/**
 * find_listint_loop - Finds the node where a loop starts in a linked list
 * @head: Pointer to the head of the linked list
 *
 * Return: Address of the node where the loop starts, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle = head;
	listint_t *hare = head;

	if (head == NULL || head->next == NULL)
		return (NULL);

	while (hare != NULL && hare->next != NULL)
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
