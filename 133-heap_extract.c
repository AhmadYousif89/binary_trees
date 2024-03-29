#include "binary_trees.h"

/**
 * _size - measures the size of a binary tree.
 * @tree: pointer to the root node of the tree.
 * Return: the tree's size or 0 if tree is NULL.
 */
size_t _size(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (_size(tree->left) + _size(tree->right) + 1);
}

/**
 * swap - swaps the values of two nodes
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 */
void swap(heap_t *node1, heap_t *node2)
{
	int temp = node1->n;

	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify_down - Restores the Max Heap property by moving a node down the heap
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest;

	if (root == NULL)
		return;

	while (root->left || root->right)
	{
		largest = root->left;

		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest->n <= root->n)
			break;

		swap(root, largest);
		root = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *last_node;

	if (root == NULL || *root == NULL)
		return (0);

	extracted_value = (*root)->n;
	if (_size(*root) == 1)
	{
		free(*root);
		*root = NULL;
		return (extracted_value);
	}

	/* Find the last level-order node */
	last_node = *root;
	while (last_node->left || last_node->right)
	{
		if (last_node->right)
			last_node = last_node->right;
		else
			last_node = last_node->left;
	}

	/* Swap values of root and last node */
	swap(*root, last_node);

	/* Free last node */
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	free(last_node);

	heapify_down(*root);

	return (extracted_value);
}
