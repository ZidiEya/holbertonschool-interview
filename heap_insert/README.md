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

