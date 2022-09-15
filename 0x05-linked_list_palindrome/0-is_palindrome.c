#include "lists.h"

/**
 * is_palindrome - prototype that defines if a linked list is a palindrome
 * @head: the double pointer to head
 * Return: 1 if it's palindrome or 0
 */

int is_palindrome(listint_t **head)
{
	int size_of_list, i;
	listint_t *current_1;

	if (head == NULL || *head == NULL)
		return (1);
	size_of_list = get_list_size(*head);
	current_1 = *head;
	for (i = 0; i < size_of_list; i++)
	{
		if (current_1->n != (last_element(*head, size_of_list - i))->n)
			return (0);
		current_1 = current_1->next;
	}
	return (1);
}

/**
 * get_list_size - func that gets size of a list
 * @current: current position in the list
 * Return: the size
 */
int get_list_size(listint_t *current)
{
	int i;

	i = 0;
	while (current->next != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

/**
 * last_element - func that gets to the last element in the list that are being check
 * @current_2: the current position in the list
 * @i: the index
 * Return: the pointer to the node needed
 */
listint_t *last_element(listint_t *current_2, int i)
{
	int count;

	for (count = 0; count < i; count++)
		current_2 = current_2->next;
	return (current_2);
}
