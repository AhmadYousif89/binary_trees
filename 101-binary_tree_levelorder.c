#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs level-order traversal of a binary tree
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function traverses the binary tree in level-order
 *              and calls the provided function for each node, passing
 *              the value of the node as a parameter to the function.
 *              If tree or func is NULL, it does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = 0, rear = -1;
	const binary_tree_t **queue, *current;

	if (tree == NULL || func == NULL)
		return;

	/* Queue to store nodes for level-order traversal */
	queue = malloc(sizeof(binary_tree_t *));
	if (queue == NULL)
		return;

	queue[++rear] = (binary_tree_t *)tree;
	while (front <= rear)
	{
		current = queue[front++]; /* Dequeue a node */
		func(current->n);

		/* Enqueue left node */
		if (current->left)
		{
			queue = realloc(queue, (rear + 2) * sizeof(binary_tree_t *));
			if (queue == NULL)
				return;
			queue[++rear] = current->left;
		}

		/* Enqueue right node */
		if (current->right)
		{
			queue = realloc(queue, (rear + 2) * sizeof(binary_tree_t *));
			if (queue == NULL)
				return;
			queue[++rear] = current->right;
		}
	}

	free(queue);
}
