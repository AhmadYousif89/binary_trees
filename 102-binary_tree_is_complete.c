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
 * @root: Pointer to the root node of the tree to check
 * @index: starting node index
 * @number_nodes: total number of the tree nodes
 * Return: 1 if the tree is complete, 0 otherwise
 */
int check_complete(const binary_tree_t *root, int index, int number_nodes)
{
	if (root == NULL)
		return (1);

	if (index >= number_nodes)
		return (0);

	return (check_complete(root->left, 2 * index + 1, number_nodes) &&
			check_complete(root->right, 2 * index + 2, number_nodes));
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
