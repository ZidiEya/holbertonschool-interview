#include "binary_trees.h"
#include <limits.h>

/**
 * height - Returns the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height of the tree, or -1 if NULL
 */
int height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (-1);

    int left_h = height(tree->left);
    int right_h = height(tree->right);

    return (left_h > right_h ? left_h + 1 : right_h + 1);
}

/**
 * is_bst - Recursively checks if a tree is a valid BST
 * @tree: Pointer to the node
 * @min: Minimum valid value
 * @max: Maximum valid value
 * Return: 1 if valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (is_bst(tree->left, min, tree->n) &&
            is_bst(tree->right, tree->n, max));
}

/**
 * is_avl - Recursive AVL checker
 * @tree: Pointer to the root
 * @min: Minimum value
 * @max: Maximum value
 * Return: 1 if tree is AVL, 0 otherwise
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
    int left_h, right_h;

    if (tree == NULL)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    left_h = height(tree->left);
    right_h = height(tree->right);

    if (abs(left_h - right_h) > 1)
        return (0);

    return (is_avl(tree->left, min, tree->n) &&
            is_avl(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (is_avl(tree, INT_MIN, INT_MAX));
}
