#include "binary_trees.h"

/**
 * _size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree.
 * Return: size or 0 if tree is NULL
 */
size_t _size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + (_size(tree->left) + _size(tree->right)));
}

/**
 * heap_to_sorted_array - Binary Max Heap to a sorted array of integers.
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 *
 * Return: the generated array
 *         NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *array = NULL;

	if (heap == NULL || size == 0)
		return (NULL);

	*size = _size(heap);

	array = malloc(sizeof(int) * (*size));
	if (array == NULL)
		return (NULL);

	for (i = 0; heap; i++)
		array[i] = heap_extract(&heap);

	return (array);
}
