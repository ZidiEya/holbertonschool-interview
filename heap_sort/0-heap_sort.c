#include "sort.h"

/**
 * swap - Swap two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/**
 * heapify - Maintains the max-heap property for a subtree
 * @array: The array to sort
 * @size: Total size of the array
 * @i: Index of the root of the subtree
 * @heap_size: Size of the heap
 */
void heapify(int *array, size_t size, size_t i, size_t heap_size)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < heap_size && array[left] > array[largest])
		largest = left;
	if (right < heap_size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, heap_size);
	}
}

/**
 * heap_sort - Sorts an array using the Heap sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;

	if (!array || size < 2)
		return;

	/* Build max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	/* Extract elements from heap */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}
