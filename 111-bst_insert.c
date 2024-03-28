#include "binary_trees.h"

/**
 * insert - Inserts a value into a Binary Search Tree (BST)
 * @node: Pointer to the root node of the BST or subtree
 * @value: Value to be inserted
 *
 * Return: Pointer to the root node of the modified BST
 */
bst_t *insert(bst_t *node, int value)
{
	if (value < node->n)
		node->left = insert(node->left, value);
	else
		node->right = insert(node->right, value);

	return ((binary_tree_t *)node);
}

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST)
 * @tree: Pointer to a pointer to the root node of the BST
 * @value: Value to be inserted
 *
 * Return: Pointer to the root node of the modified BST
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL || *tree == NULL)
		return (binary_tree_node(*tree, value));

	*tree = insert(*tree, value);
	return (*tree);
}
