#include "binary_trees.h"

/**
 * add_into_AVL - Inserts a value into an AVL tree recursively.
 *
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *add_into_AVL(avl_t **tree, avl_t **new, int value)
{
	int bf = 0;

	if (*tree == NULL)
		return (*new = binary_tree_node(*tree, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = add_into_AVL(&(*tree)->left, new, value);
		(*tree)->left->parent = *tree;
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = add_into_AVL(&(*tree)->right, new, value);
		(*tree)->right->parent = *tree;
	}
	else
		return (*tree);

	/* Step 2: Update height and balance factor */
	bf = binary_tree_balance(*tree);
	/* Step 3: Perform rotations if necessary */
	/* Left-Left Case */
	if (bf > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));
	/* Right-Right Case */
	if (bf < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));
	/* Left-Right Case */
	if (bf > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}
	/* Right-Left Case */
	if (bf < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL || *tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	add_into_AVL(tree, &new, value);
	return (new);
}
