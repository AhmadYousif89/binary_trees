#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: the tree's depth or 0 if tree is NULL.
 */
int get_depth(const binary_tree_t *node)
{
	int d = 0;

	while (node)
	{
		d++;
		node = node->left;
	}
	return (d);
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
 *
 * Theorems:
 * A perfect binary tree of height h has 2h + 1 – 1 node.
 * A perfect binary tree with n nodes has height log(n + 1) – 1 = Θ(ln(n)).
 * A perfect binary tree of height h has 2h leaf nodes.
 * The average depth of a node in a perfect binary tree is Θ(ln(n)).
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)get_size(tree) == (1 << get_depth(tree)) - 1);
}
