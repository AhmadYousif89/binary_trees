#include "binary_trees.h"

/**
 * _insert_node - Insert a node value in a AVL tree.
 * @tree: pointer of root node of the AVL tree struct.
 * @new: pointer left or right insertion.
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
 * avl_insert - Insert a new node into an AVL tree.
 * @tree: pointer to the root node of the AVL tree to insert into.
 * @value: the value to be stored in the node
 * Return: the inserted node, or NULL.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *inserted = NULL;

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	_insert_node(tree, &inserted, value);
	return (inserted);
}
