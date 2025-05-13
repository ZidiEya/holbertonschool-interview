      0-binary_tree_node.c



       function to create a new node in a binary tree
Prototype:
c
Copier
Modifier
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
parent: A pointer to the parent node of the node to create.

value: The integer value to store in the new node.

The function should return a pointer to the newly created node, or NULL if memory allocation fails.

Explanation:
The node must be initialized with the provided value.

The left and right child pointers of the new node should be set to NULL since no children are assigned upon creation.

The parent pointer should point to the given parent.
🌳 Binary Trees Overview
A binary tree is a data structure where each node has:

A value

A pointer to a left child

A pointer to a right child

A pointer to a parent (optional, but used in your project)

📘 Types:
Binary Tree: Each node has ≤2 children.

Binary Search Tree (BST): Left < Root < Right.

Max Binary Heap: A complete binary tree where parent ≥ children.

Min Binary Heap: A complete binary tree where parent ≤ children.

📐 Structure in C
c
Copier
Modifier
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;
🧱 Common Operations (functions you should know or implement)
✅ Create a new node
c
Copier
Modifier
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
Creates a new node with a given value and parent.

✅ Insert a node (for Heaps)
c
Copier
Modifier
heap_t *heap_insert(heap_t **root, int value);
Inserts a value into a Max Heap while maintaining the complete tree and heap order.

✅ Measure size of a binary tree
c
Copier
Modifier
size_t binary_tree_size(const binary_tree_t *tree);
Useful when determining the position for new heap insertions.

✅ Print a tree (for debugging)
A helper function often provided in Holberton projects:

c
Copier
Modifier
void binary_tree_print(const binary_tree_t *);
This visualizes the tree in a nice readable format.

🔄 Max Heap Rules Reminder
For a Max Binary Heap:

It must be complete: every level filled left to right.

Every node must be greater than or equal to its children.

Insertion is done at the leftmost available spot, and the value is "heapified up" (swapped with parents if larger).
