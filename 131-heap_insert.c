#include "binary_trees.h"

/**
 * get_size - measures the size of a binary tree.
 * @tree: pointer to the root node of the tree.
 * Return: the tree's size or 0 if tree is NULL.
 */
size_t get_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (get_size(tree->left) + get_size(tree->right) + 1);
}

/**
 * heapify_up - Restores the Max Heap property by moving a node up the heap
 * @node: Pointer to the node to be moved up
 * Return: Pointer to the node
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int total_nodes, sub, bit, lvl;
	heap_t *tree, *new_node;

	if (root == NULL || *root == NULL)
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	total_nodes = get_size(tree);

	for (lvl = 0, sub = 1; total_nodes >= sub; sub *= 2, lvl++)
		total_nodes -= sub;

	for (bit = 1 << (lvl - 1); bit != 1; bit >>= 1)
		tree = total_nodes & bit ? tree->right : tree->left;

	new_node = binary_tree_node(tree, value);
	total_nodes & 1 ? (tree->right = new_node) : (tree->left = new_node);

	new_node = heapify_up(new_node);

	return (new_node);
}
