#include "binary_trees.h"
avl_t *build_avl_tree(avl_t *parent, int *array, int start, int end);

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl_tree(NULL, array, 0, size - 1));
}

/**
 * build_avl_tree - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Index of the first element of the current subtree
 * @end: Index of the last element of the current subtree
 * Return: Pointer to the root node of the created AVL subtree
 */
avl_t *build_avl_tree(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		root = binary_tree_node(parent, array[mid]);
		root->left = build_avl_tree(root, array, begin, mid - 1);
		root->right = build_avl_tree(root, array, mid + 1, last);
		return (root);
	}

	return (NULL);
}
