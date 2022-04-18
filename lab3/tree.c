#include <stdio.h>
#include <stdlib.h>
#include "tree_data.h"
#include "tree_node.h"
#include "tree.h"

struct Tree *initTree()
{
	struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
	tree->root = NULL;
	return tree;
}

struct Tree *generateTree(int n, int arr[]) // Use as Blackbox
{
	struct Tree *tree = initTree();
	struct TreeNode *queue[n + 10];
	tree->root = initTreeNode();
	tree->root->data->data = arr[0];
	queue[0] = tree->root;
	int pos = 0, f = 0, b = 1;
	while (pos < n)
	{
		if (arr[pos] == -1)
		{
			++pos;
			continue;
		}
		struct TreeNode *node = queue[f++];
		if (pos * 2 + 1 < n && arr[pos * 2 + 1] >= 0)
		{
			node->left = initTreeNode();
			node->left->data->data = arr[pos * 2 + 1];
			queue[b++] = node->left;
		}
		if (pos * 2 + 2 < n && arr[pos * 2 + 2] >= 0)
		{
			node->right = initTreeNode();
			node->right->data->data = arr[pos * 2 + 2];
			queue[b++] = node->right;
		}
	}
	return tree;
}

void _printInorderTraversalRecursive(struct TreeNode *node)
{
	// Implementation here
}

void printInorderTraversalRecursive(struct Tree *tree)
{
	_printInorderTraversalRecursive(tree->root);
}

void _printPostorderTraversalRecursive(struct TreeNode *node)
{
	// Implementation here
}

void printPostorderTraversalRecursive(struct Tree *tree)
{
	_printPostorderTraversalRecursive(tree->root);
}

void printInorderTraversalIterative(struct Tree *tree)
{
	// Implementation here
}

void printPostorderTraversalIterative(struct Tree *tree)
{
	// Implementation here
}

int isBinarySearchTree(struct Tree *tree)
{
	// Implementation here
}

int getHeightTree(struct Tree *tree)
{
	// Implementation here
}

void _deleteTree(struct TreeNode *node)
{
	if (node->left != NULL)
		_deleteTree(node->left);
	if (node->right != NULL)
		_deleteTree(node->right);
	deleteTreeNode(node);
}

void deleteTree(struct Tree *tree)
{
	_deleteTree(tree->root);
	free(tree);
}
