#include "binary_trees.h"
#include <stdlib.h>

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to the root node, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (build_avl(array, 0, size - 1, NULL));
}

/**
 * build_avl - Recursive function to build AVL from sub-array
 * @array: Sorted array of integers
 * @start: Start index
 * @end: End index
 * @parent: Parent node
 * Return: Pointer to new node
 */
avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);

	root->n = array[mid];
	root->parent = parent;
	root->left = build_avl(array, start, mid - 1, root);
	root->right = build_avl(array, mid + 1, end, root);

	return (root);
}
