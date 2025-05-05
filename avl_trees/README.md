function that checks if a binary tree is a valid AVL Tree

Prototype: int binary_tree_is_avl(const binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to check
Your function must return 1 if tree is a valid AVL Tree, and 0 otherwise
If tree is NULL, return 0
Properties of an AVL Tree:

An AVL Tree is a BST
The difference between heights of left and right subtrees cannot be more than one
The left and right subtree each must also be a binary search tree


🌳 AVL Trees — Overview & Implementation Help
An AVL tree is a self-balancing binary search tree (BST). Named after its inventors Adelson-Velsky and Landis, it ensures that the height difference (balance factor) between left and right subtrees of any node is at most 1, which guarantees O(log n) operations for insertion, deletion, and lookup.

🔑 AVL Tree Properties
Binary Search Tree:

Left subtree has values less than node

Right subtree has values greater than node

Balanced:

Balance Factor = height(left) - height(right)

Valid if the balance factor ∈ {-1, 0, 1}

Rotations are used to maintain balance:

Left Rotation (RR case)

Right Rotation (LL case)

Left-Right Rotation (LR case)

Right-Left Rotation (RL case)
