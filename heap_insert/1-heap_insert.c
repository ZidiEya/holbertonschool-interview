#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * @value: The value to insert into the heap.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent, *current;
    size_t level = 0;
    size_t max_level = 0;
    size_t i = 0;

    if (root == NULL)
        return (NULL);

    /* Create the new node */
    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    /* Find the level of the tree and where to insert the node */
    current = *root;
    while (current->left || current->right)
    {
        level++;
        current = current->left ? current->left : current->right;
    }

    /* Insert node at the first available position (complete binary tree) */
    if (current->left == NULL)
    {
        current->left = new_node;
        new_node->parent = current;
    }
    else if (current->right == NULL)
    {
        current->right = new_node;
        new_node->parent = current;
    }

    /* Restore Max Heap property */
    while (new_node->parent && new_node->parent->n < new_node->n)
    {
        parent = new_node->parent;
        /* Swap values */
        new_node->n = parent->n;
        parent->n = value;
        new_node = parent;
    }

    return (new_node);
}
