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
 * is_AVL - Check if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to rotate
 * Return: 1 if tree is a valid AVL, and 0 otherwise
 */
int is_AVL(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (1);

	left_height = get_height(tree->left);
	right_height = get_height(tree->right);

	balance_factor = left_height - right_height;

	if (balance_factor < -1 || balance_factor > 1)
		return (0);

	return (is_AVL(tree->left) && is_AVL(tree->right));
}

/**
 * is_BST - Checks if a binary tree is a valid Binary Search Tree (BST)
 * @node: Pointer to the root node of the binary tree or subtree
 * @min: The minimum value allowed for nodes in the subtree
 * @max: The maximum value allowed for nodes in the subtree
 * Return: 1 if the tree is a valid BST 0 otherwise.
 */
int is_BST(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	return (is_BST(node->left, min, node->n - 1) &&
			is_BST(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: 1 if tree is a valid AVL, and 0 otherwise
 *
 * Properties of an AVL Tree:
 * => An AVL Tree is a BST.
 * => The difference between heights of left and right subtrees
 *		cannot be more than one.
 * => The left and right subtrees must also be AVL trees.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (is_BST(tree, INT_MIN, INT_MAX) == 0)
		return (0);

	return (is_AVL(tree));
}
