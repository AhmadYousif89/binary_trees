#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 *
 * Description: A tree is considered a complete binary tree, if it adheres to
 * these two rules:
 * 1. All levels except the last are completely filled
 * 2. The last level, if not completely filled, must have all nodes as far left
 *    as possible.
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue, *current;
	int lvl_has_ended = 0, front = 0, rear = -1;

	if (tree == NULL)
		return (0);

	queue = malloc(sizeof(binary_tree_t *));
	if (queue == NULL)
		return (0);

	queue[++rear] = tree;
	while (front <= rear)
	{
		current = queue[front++];
		/* If we have encountered a NULL node, mark the end of the level */
		if (current == NULL)
			lvl_has_ended = 1;
		else
		{
			/* If we have previously encountered the end of the level, */
			/* but the current node is not NULL, then the tree is not complete */
			if (lvl_has_ended)
				return (0);
			/* Enqueue the left and right children */
			queue = realloc(queue, (rear + 2) * sizeof(binary_tree_t *));
			if (queue == NULL)
				return (0);
			queue[++rear] = current->left;
			queue[++rear] = current->right;
		}
	}
	/* If we reach here, the tree is complete */
	free(queue);
	return (1);
}
