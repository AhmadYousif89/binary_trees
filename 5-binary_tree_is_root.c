#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a given node is a root.
 * @node: pointer to the tree node.
 *
 * Return: 1 or 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node && node->parent == NULL);
}
