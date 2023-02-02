#include "lists.h"

/**
* check_cycle - func that Chekcks if LL has a cyle in it
*
* @list: listint pointer to linked list
*
* Return: 0 if there is no cycle, 1 if there is  cycle
*/

int check_cycle(listint_t *list)
{
	listint_t *slow = list;
	listint_t *fast = list;

	while (slow && fast && fast->next)
	{
		/* slow increments by one node, faster than two nodes */
		slow = slow->next;
		fast = fast->next->next;

		/* if they collide than the cycle is found */
		if (slow == fast)
		{
			return (1);
		}
	}
	return (0);
}
