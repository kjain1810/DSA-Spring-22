#include <stdio.h>
#include <stdlib.h>
#include "tree_data.h"
#include "tree_node.h"
#include "tree.h"

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

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
		// printf("test %d\n", arr[pos]);
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
		++pos;
	}
	return tree;
}

void _printInorderTraversalRecursive(struct TreeNode *node)
{
	if (node->left != NULL)
		_printInorderTraversalRecursive(node->left);
	printf("%d ", node->data->data);
	if (node->right != NULL)
		_printInorderTraversalRecursive(node->right);
}

void printInorderTraversalRecursive(struct Tree *tree)
{
	_printInorderTraversalRecursive(tree->root);
	printf("\n");
}

void _printPostorderTraversalRecursive(struct TreeNode *node)
{
	if (node->left != NULL)
		_printPostorderTraversalRecursive(node->left);
	if (node->right != NULL)
		_printPostorderTraversalRecursive(node->right);
	printf("%d ", node->data->data);
}

void printPostorderTraversalRecursive(struct Tree *tree)
{
	_printPostorderTraversalRecursive(tree->root);
	printf("\n");
}

void printInorderTraversalIterative(struct Tree *tree)
{
	struct TreeNode *stack[1000];
	int top = 0;
	struct TreeNode *node = tree->root;
	while (top > 0 || node != NULL)
	{
		while (node != NULL)
		{
			stack[top++] = node;
			node = node->left;
		}
		node = stack[--top];
		printf("%d ", node->data->data);
		node = node->right;
	}
}

void printPostorderTraversalIterative(struct Tree *tree)
{
	// struct TreeNode *stack[1000];
	// int top = 0;
	// struct TreeNode *node = tree->root;
	// while (top > 0 || node != NULL)
	// {
	// 	while (node != NULL)
	// 	{
	// 		stack[top++] = node;
	// 		node = node->left;
	// 	}
	// 	node = stack[--top];
	// 	printf("%d ", node->data->data);
	// 	node = node->right;
	// }
}

int _isBinarySearchTree(struct TreeNode *node)
{
	int flag = 1;
	if (node->left != NULL)
		flag &= _isBinarySearchTree(node->left);
	if (node->right != NULL)
		flag &= _isBinarySearchTree(node->right);

	if (node->left == NULL && node->right == NULL)
	{
		node->data->is_BST = 1;
		node->data->minval = node->data->maxval = node->data->data;
	}
	if (node->left != NULL && node->left->data->maxval > node->data->data)
		flag = 0;
	if (node->right != NULL && node->right->data->minval <= node->data->data)
		flag = 0;
	node->data->minval = node->data->maxval = node->data->data;
	if (node->left != NULL)
	{
		node->data->minval = min(node->data->minval, node->left->data->minval);
		node->data->maxval = max(node->data->maxval, node->left->data->maxval);
	}
	if (node->right != NULL)
	{
		node->data->minval = min(node->data->minval, node->right->data->minval);
		node->data->maxval = max(node->data->maxval, node->right->data->maxval);
	}
	node->data->is_BST = flag;
	// printf("test %d %d %d %d\n", flag, node->data->data, node->data->minval, node->data->maxval);
	return flag;
}

int isBinarySearchTree(struct Tree *tree)
{
	return _isBinarySearchTree(tree->root);
}

int _getHeightTree(struct TreeNode *node, int height)
{
	int ans = 0;
	if (node->left != NULL)
		ans = max(ans, _getHeightTree(node->left, height + 1));
	if (node->right != NULL)
		ans = max(ans, _getHeightTree(node->right, height + 1));
	if (node->left == NULL && node->right == NULL)
		return height;
	return ans;
}

int getHeightTree(struct Tree *tree)
{
	return _getHeightTree(tree->root, 1);
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
