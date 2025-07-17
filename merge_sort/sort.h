#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/* Print function provided */
void print_array(const int *array, size_t size);

/* merge sort functions */
void merge_sort(int *array, size_t size);
void merge_sort_holder(int *array, size_t size, int *holder);
void merge(int *holder, int *array, int mid, size_t size);

#endif /* SORT_H */
