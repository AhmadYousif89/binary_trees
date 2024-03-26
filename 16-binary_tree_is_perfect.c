#include "binary_trees.h"

/**
 * get_height- measures the height of a binary tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: the height of the tree, or 0 if tree is NULL.
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = get_height(tree->left);
	right = get_height(tree->right);

	return (1 + (left > right ? left : right));
}

/**
 * get_size - measures the size of a binary tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: the tree's size or 0 if tree is NULL.
 */
size_t get_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (get_size(tree->left) + get_size(tree->right) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = get_height(tree);
	size_t size = get_size(tree);

	/* A perfect binary tree has 2^h - 1 nodes, where h is the height */
	return ((int)size == (1 << height) - 1);
}
