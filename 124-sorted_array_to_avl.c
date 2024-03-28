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

	return (build_avl_tree(NULL, array, 0, (int)size - 1));
}

/**
 * build_avl_tree - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Index of the first element of the current subtree
 * @parent: Pointer to the root node
 * @end: Index of the last element of the current subtree
 * Return: Pointer to the root node of the created AVL subtree
 */
avl_t *build_avl_tree(avl_t *parent, int *array, int start, int end)
{
	avl_t *root;
	int mid = 0;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node((binary_tree_t *)parent, array[mid]);
	root->parent = parent;
	root->left = build_avl_tree(root, array, start, mid - 1);
	root->right = build_avl_tree(root, array, mid + 1, end);

	return (root);
}
