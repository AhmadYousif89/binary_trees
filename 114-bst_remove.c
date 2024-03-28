#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree after removing the value,
 *         or NULL if the value is not found or if the tree is empty
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else /* value == root->n */
	{
		/* Case 1: No child or one child */
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else /* Case 2: Two childern */
		{
			temp = root->right;
			while (temp->left)
				temp = temp->left;
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}

	return (root);
}
