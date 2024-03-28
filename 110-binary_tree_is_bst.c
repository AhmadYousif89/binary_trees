#include "binary_trees.h"

/**
 * is_BST - Checks if a binary tree is a valid Binary Search Tree (BST)
 *
 * @node: Pointer to the root node of the binary tree or subtree
 * @min: The minimum value allowed for nodes in the subtree
 * @max: The maximum value allowed for nodes in the subtree
 *
 * Description:
 * This function recursively checks if the tree satisfies the properties of a
 * Binary Search Tree (BST). It ensures that for each node, its value falls
 * within the specified range (min, max) and checks the left and right subtrees
 * to verify the BST property.
 *
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
 * binary_tree_is_bst - Check if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 *
 * Properties of a Binary Search Tree:
 * All nodes of left subtree are less than the root node.
 * All nodes of right subtree are more than the root node.
 * Both subtrees of each node are also BSTs.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((is_BST(tree, INT_MIN, INT_MAX)));
}
