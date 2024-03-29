#include "binary_trees.h"

/**
 * _height - Measures the height of a binary tree.
 * @tree: Pointer to the root node.
 * Return: Height or 0 if tree is NULL.
 */
size_t _height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = _height(tree->left);
	right = _height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
 * pre_order - Goes through a binary tree using pre-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @node: Will be last node in traverse.
 * @height: Height of tree.
 *
 * Return: No Return.
 */
void pre_order(heap_t *tree, heap_t **node, size_t height)
{
	if (tree == NULL)
		return;

	if (height == 0)
		*node = tree;

	height--;

	pre_order(tree->left, node, height);
	pre_order(tree->right, node, height);
}

/**
 * swap - swaps the values of two nodes
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 */
void swap(heap_t *node1, heap_t *node2)
{
	node1->n ^= node2->n;
	node2->n ^= node1->n;
	node1->n ^= node2->n;
}

/**
 * heapify_down - Heapifies max binary heap.
 * @root: Pointer to binary heap.
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
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: A double pointer to the root node of heap.
 * Return: The value stored in the root node, 0 on failure.
 */
int heap_extract(heap_t **root)
{
	heap_t *tree, *node = NULL;
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	tree = *root;
	value = (tree)->n;
	if ((tree)->left == NULL && (tree)->right == NULL)
	{
		*root = NULL;
		free(tree);
		return (value);
	}

	pre_order(*root, &node, _height(tree) - 1);

	(tree)->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;

	free(node);
	heapify_down(tree);
	return (value);
}
