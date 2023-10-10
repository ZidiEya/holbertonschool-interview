#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 *add_node_end - Add a node to the end of a double circular linked list
 *
 * @list: the list to modify
 * @str: the string to copy into the node
 * Return: Address of node, or none on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *head;
	char *s;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	s = strdup(str);
	if (!s)
		return (NULL);
	new_node->str = s;
	if (!(*list))
	{
		*list = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return (new_node);
	}
	head = *list;
	new_node->next = head;
	new_node->prev = head->prev;
	head->prev->next = new_node;
	head->prev = new_node;
	return (new_node);
}

/**
 *add_node_begin - Add node to the beginning of a double circular
 *linked list
 * @list: list to modify
 * @str: string to copy into the node
 * Return: Address of new node, or Null on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *head;
	char *s;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	s = strdup(str);
	if (!s)
		return (NULL);
	new_node->str = s;
	if (!(*list))
	{
		*list = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;

		return (new_node);
	}
	head = *list;
	new_node->next = head;
	new_node->prev = head->prev;
	head->prev->next = new_node;
	head->prev = new_node;
	*list = new_node;
	return (new_node);
}
