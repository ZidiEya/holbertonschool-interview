#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

/* Type definitions for the binary tree node */
typedef struct binary_tree_s binary_tree_t;

/* Function prototypes */

/* Creates a new binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Prints the binary tree (for visualization purposes) */
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
