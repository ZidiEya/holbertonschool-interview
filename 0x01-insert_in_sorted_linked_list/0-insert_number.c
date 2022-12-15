#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * insert_node :the  func
 * Return: the new node or NULL
 * @head: the pointer to the pointer
 * @number:the Data
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *newnode;
    listint_t *tmp = *head;

    newnode = malloc(sizeof(listint_t));
    if (newnode == NULL)
    {
        return (NULL);
    }
    newnode->n = number;
    if (*head == NULL)
    {
        *head = newnode;
        newnode->next = NULL;
        return (newnode);
    }
    if (tmp->next == NULL)
    {
        newnode->next = NULL;
        tmp->next = newnode;
        return (newnode);
    }
    if (number <= tmp->n)
    {
        newnode->next = tmp;
        *head = newnode;
        return (newnode);
    }
    while (tmp->next)
    {
        if (number <= (tmp->next->n))
        {
            newnode->next = tmp->next;
            tmp->next = newnode;
            return (newnode);
        }
        tmp = tmp->next;
    }
    tmp->next = newnode;
    newnode->next = NULL;
    return (newnode);
}
