#include "binary_trees.h"

/**
 * heap_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Size
 */
size_t heap_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * get_node_at_index - Gets node using binary representation of index
 * @root: Pointer to root
 * @index: Index to find
 * Return: Pointer to node
 */
heap_t *get_node_at_index(heap_t *root, size_t index)
{
	size_t mask = 1UL << (63 - __builtin_clzl(index));
	heap_t *node = root;

	while (mask >>= 1)
	{
		if (!node)
			return (NULL);
		if (index & mask)
			node = node->right;
		else
			node = node->left;
	}
	return (node);
}

/**
 * heapify_down - Moves a node down the tree to maintain heap property
 * @root: Pointer to the node
 */
void heapify_down(heap_t *root)
{
	heap_t *largest, *left, *right;
	int tmp;

	if (!root)
		return;

	while (1)
	{
		largest = root;
		left = root->left;
		right = root->right;

		if (left && left->n > largest->n)
			largest = left;
		if (right && right->n > largest->n)
			largest = right;

		if (largest == root)
			break;

		tmp = root->n;
		root->n = largest->n;
		largest->n = tmp;

		root = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to root node
 * Return: Value of extracted node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last, *parent;
	int value;
	size_t size;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	size = heap_size(*root);
	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = get_node_at_index(*root, size - 1);

	(*root)->n = last->n;
	parent = last->parent;
	if (parent->right == last)
		parent->right = NULL;
	else
		parent->left = NULL;

	free(last);

	heapify_down(*root);
	return (value);
}
