#include "binary_trees.h"

/**
 * _insert_node - node value instertion in a AVL.
 * @tree: type **pointer of root node of the AVL tree struct.
 * @new: type**pointer left or right insertion.
 * @value: insertion value of the AVL.
 * Return: pointer to the new root after insertion otherwise NULL
 */
avl_t *_insert_node(avl_t **tree, avl_t **new, int value)
{
	int bf;

	if (*tree == NULL)
		return (*new = binary_tree_node(*tree, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = _insert_node(&(*tree)->left, new, value);
		(*tree)->left->parent = *tree;
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = _insert_node(&(*tree)->right, new, value);
		(*tree)->right->parent = *tree;
	}
	else
		return (*tree);

	bf = binary_tree_balance(*tree);

	if (bf > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bf > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bf < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bf < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}
/**
 * avl_insert - inserts a value into an AVL tree.
 * @tree: type **pointer to the root node of the AVL tree to insert into.
 * @value: value to store in the node to be inserted
 * Return: inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	_insert_node(tree, &new, value);
	return (new);
}
