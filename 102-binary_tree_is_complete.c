#include "binary_trees.h"

/**
 * get_size - measures the size of a binary tree.
 * @tree: pointer to the root node of the tree.
 *
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
 *
 * @tree: Pointer to the root node of the tree to check
 * @index: the node index position
 * @total_nodes: total number of the tree nodes
 *
 * Return: 1 if the tree is complete, 0 otherwise
 *
 * Description:
 * This function recursively checks if the binary tree starting
 * from the given root node is complete.
 * It traverses the tree in a depth-first manner, assigning an index to each
 * node based on its position, and compares the index of each node with
 * the total number of nodes to determine completeness.
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
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 *
 * Theroms:
 * A complete binary tree is a tree in which all the levels are completely
 * filled except possibly the lowest one, which is filled from the left.
 * It is just like a full binary tree, but with two major differences:
 * 1. All the leaf elements must lean towards the left side.
 * 2. The last leaf element might not have a right sibling.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_complete(tree, 0, get_size(tree)));
}
