#include "binary_trees.h"

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
		return (*tree = binary_tree_node(NULL, value));

	if (value < (*tree)->n)
	{
		if ((*tree)->left)
			return (bst_insert(&(*tree)->left, value));
		return ((*tree)->left = binary_tree_node(*tree, value));
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right)
			return (bst_insert(&(*tree)->right, value));
		return ((*tree)->right = binary_tree_node(*tree, value));
	}

	/* Value already exists in the tree (duplicate) */
	return (NULL);
}
