#include "binary_trees.h"
avl_t *balance_avl(avl_t *root);

/**
 * avl_remove - Removes a node from a AVL Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree after removing the value,
 *         or NULL if the value is not found or if the tree is empty
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (root == NULL)
		return (NULL);
	/* Remove node logic */
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
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
		/* Case 2: Two childern */
		temp = root->right;
		while (temp->left)
			temp = temp->left;
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}

	/* Balance the AVL tree if needed */
	root = balance_avl(root);

	return (root);
}

/**
 * balance_avl - Balance the AVL tree.
 * @root: Pointer to the root node of the tree
 * Return: Pointer to the root node.
 */
avl_t *balance_avl(avl_t *root)
{
	int bf;

	bf = binary_tree_balance(root);
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
