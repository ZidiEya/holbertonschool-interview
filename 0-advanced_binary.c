#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @left: The starting index
 * @right: The ending index
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		if (i > left)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * binary_search_recursive - Recursive binary search for first occurrence
 * @array: Pointer to first element of array
 * @left: Left boundary index
 * @right: Right boundary index
 * @value: Value to search for
 * Return: Index of first occurrence or -1
 */
int binary_search_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);
	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);
		else
			return (binary_search_recursive(array, left, mid, value));
	}
	else if (array[mid] < value)
		return (binary_search_recursive(array, mid + 1, right, value));
	else
		return (binary_search_recursive(array, left, mid - 1, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using recursion
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: First index where value is located, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}
