get_node_at_index() uses the binary representation of the heap index to find the last inserted node.

__builtin_clzl() is a GCC builtin function that counts leading zeros. You can replace this if you use a different compiler.

✅ Objective
Implement a function:

c
Copier
Modifier
int heap_extract(heap_t **root);
That:

Extracts the root node of a Max Binary Heap

Maintains the Max Heap property after extraction

✅ Requirements
No global variables

No more than 5 functions per file

Follow Betty style

Header file: binary_trees.h (with include guards)

Use only standard C (Ubuntu 14.04, gcc 4.8.4)

Allowed editors: vi, vim, emacs

✅ Files Implemented
1. binary_trees.h
Defines the structure and prototype:

c
Copier
Modifier
#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

int heap_extract(heap_t **root);

#endif /* BINARY_TREES_H */
2. 0-heap_extract.c
Includes:

heap_size – to compute total nodes

get_node_at_index – to find the last node via index

heapify_down – to restore heap after root removal

heap_extract – the main function

Full code included above.

✅ How It Works
Save the root value.

If only 1 node, free it and return.

Get the last node in the heap (based on size).

Replace root value with last node’s value.

Remove last node from tree.

Heapify down from root to restore heap property.

Return the original root value.

✅ Compilation Command
bash
Copier
Modifier
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-heap_extract.c 0-main.c binary_tree_print.c -o heap_extract
