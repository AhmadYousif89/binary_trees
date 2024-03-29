#include "binary_trees.h"

/**
 * array_to_heap - Build a Max Binary Heap tree from an array.
 * @array: pointer to the array
 * @size: the number of element in the array
 * Return: pointer to the root node of or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
