#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node
 * @parent: Pointer to the parent node
 * @value: The value to store in the new node
 *
 * Return: Pointer to the new node, or NULL if it fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    /* Initialize the new node with the given values */
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    /* Return the pointer to the new node */
    return (new_node);
}
