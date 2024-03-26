#include "binary_trees.h"

/**
 * get_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: the tree's height or 0 if tree is NULL.
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);

	left = get_height(tree->left);
	right = get_height(tree->right);
	return (1 + (left > right ? left : right));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: the balance factor of the tree or 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)(get_height(tree->left) - get_height(tree->right)));
}
