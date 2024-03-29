#include "binary_trees.h"

/**
 * get_size - measures the size of a binary tree.
 * @tree: pointer to the root node of the tree.
 * Return: the tree's size or 0 if tree is NULL.
 */
int get_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (get_size(tree->left) + get_size(tree->right) + 1);
}

/**
 * check_complete - Check if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check
 * @index: the node index position
 * @total_nodes: total number of the tree nodes
 * Return: 1 if the tree is complete, 0 otherwise
 */
int check_complete(const binary_tree_t *tree, int index, int total_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= total_nodes)
		return (0);

	return (check_complete(tree->left, 2 * index + 1, total_nodes) &&
			check_complete(tree->right, 2 * index + 2, total_nodes));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree)
{
	return (check_complete(tree, 0, get_size(tree)));
}

/**
 * is_heap - Checks if a binary tree is a valid max heap (deprecated)
 * @root: Pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid max heap, 0 otherwise.
 * Description:
 * This function checks if a binary tree represented by the
 * `root` node is a valid max heap.
 */
int is_heap(const heap_t *root)
{
	if (root == NULL)
		return (1);

	/* Early termination if parent value is less than a child's value */
	if ((root->left && root->left->n > root->n) ||
		(root->right && root->right->n > root->n))
		return (0);

	return (is_heap(root->left) && is_heap(root->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid max heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid max heap, 0 otherwise.
 *
 * Description:
 * This function checks if a binary tree represented by the `tree` node is
 * a valid max heap.
 */
int binary_tree_is_heap(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	if (is_complete(tree) == 0)
		return (0);

	return (is_heap(tree));
}
