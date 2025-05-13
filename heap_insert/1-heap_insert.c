#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node
 * Return: size or 0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * get_node_at_index - gets the node at a specific index using binary heap layout
 * @root: root of the heap
 * @index: index of the node
 * Return: pointer to the node
 */
heap_t *get_node_at_index(heap_t *root, size_t index)
{
    size_t path[64], i = 0, depth = 0;
    heap_t *node = root;

    if (!root)
        return (NULL);

    /* Build the path by converting index to binary and storing the bits */
    while (index > 1)
    {
        path[depth++] = index % 2;
        index /= 2;
    }

    /* Traverse path */
    for (i = depth; i > 0; i--)
    {
        if (path[i - 1] == 0)
            node = node->left;
        else
            node = node->right;
    }

    return (node);
}

/**
 * swap_up - bubble up the node to maintain Max Heap order
 * @node: pointer to node
 */
void swap_up(heap_t *node)
{
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node
 * @value: value to insert
 * Return: pointer to inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    size_t size;
    heap_t *new_node, *parent;

    if (!root)
        return (NULL);

    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    size = binary_tree_size(*root) + 1;
    parent = get_node_at_index(*root, size / 2);
    if (!parent)
        return (NULL);

    new_node = binary_tree_node(parent, value);
    if (!new_node)
        return (NULL);

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    swap_up(new_node);

    return (new_node);
}
