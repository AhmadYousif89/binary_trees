#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i, j;
	avl_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		/* Check if the current value already exists in the tree */
		for (j = 0; j < i; j++)
			if (array[j] == array[i])
				break;
		/* If the value is unique, insert it into the tree */
		if (j == i)
		{
			/* Insert the value into the AVL tree */
			if (avl_insert(&root, array[i]) == NULL)
				return (NULL); /* Insertion failed */
		}
	}

	return (root);
}
