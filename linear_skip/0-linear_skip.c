#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 *               using express lane first, then linear search.
 *
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *curr;

	if (!list)
		return (NULL);

	curr = list;
	prev = list;

	/* Traverse express lane to find range */
	while (curr->express && curr->express->n < value)
	{
		prev = curr;
		curr = curr->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       curr->index, curr->n);
	}

	/* Move one last time if express exists */
	if (curr->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       curr->express->index, curr->express->n);
		prev = curr;
		curr = curr->express;
	}
	else
	{
		/* Move to the last node if no more express lane */
		while (curr->next)
			curr = curr->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, curr->index);

	/* Linear search in the identified block */
	while (prev && prev->index <= curr->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
