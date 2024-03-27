#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes,
 *         NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	while (first)
	{
		const binary_tree_t *temp = second;

		while (temp)
		{
			if (first == temp) /* Found common ansector */
				return ((binary_tree_t *)first);
			temp = temp->parent; /* Traversing up the 2nd subtree lineage */
		}
		first = first->parent; /* Traversing up the 1st subtree lineage */
	}
	return (NULL);
}
