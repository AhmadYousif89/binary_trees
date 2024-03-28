#include "binary_trees.h"

/**
 * avl_remove - Removes a node from a AVL Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree after removing the value,
 *         or NULL if the value is not found or if the tree is empty
 */
avl_t *avl_remove(avl_t *root, int value)
{
	int bf = binary_tree_balance(root);
	avl_t *temp;

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else /* value == root->n */
	{	 /* Case 1: No child or one child */
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		temp = root->right; /* Case 2: Two childern */
		while (temp->left)
			temp = temp->left;
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}
	if (root == NULL)
		return (root);
	if (bf > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (bf < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	if (bf > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (bf < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	return (root);
}
