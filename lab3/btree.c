#include <stdio.h>
#include <stdlib.h>
#include "btree_data.h"
#include "btree_node.h"
#include "btree.h"

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

struct BTree *initBTree()
{
	struct BTree *btree = (struct BTree *)malloc(sizeof(struct BTree));
	btree->root = NULL;
	return btree;
}

struct BTree *generateBTree(int n, int arr[]) // Use as Blackbox
{
	struct BTree *btree = initBTree();
	struct BTreeNode *queue[n + 10];
	btree->root = initBTreeNode();
	btree->root->data->data = arr[0];
	queue[0] = btree->root;
	int pos = 0, f = 0, b = 1;
	while (pos < n)
	{
		// printf("test %d\n", arr[pos]);
		if (arr[pos] == -1)
		{
			++pos;
			continue;
		}
		struct BTreeNode *node = queue[f++];
		if (pos * 2 + 1 < n && arr[pos * 2 + 1] >= 0)
		{
			node->left = initBTreeNode();
			node->left->data->data = arr[pos * 2 + 1];
			queue[b++] = node->left;
		}
		if (pos * 2 + 2 < n && arr[pos * 2 + 2] >= 0)
		{
			node->right = initBTreeNode();
			node->right->data->data = arr[pos * 2 + 2];
			queue[b++] = node->right;
		}
		++pos;
	}
	return btree;
}

void _printInorderTraversalRecursive(struct BTreeNode *node)
{
	if (node->left != NULL)
		_printInorderTraversalRecursive(node->left);
	printf("%d ", node->data->data);
	if (node->right != NULL)
		_printInorderTraversalRecursive(node->right);
}

void printInorderTraversalRecursive(struct BTree *btree)
{
	_printInorderTraversalRecursive(btree->root);
	printf("\n");
}

void _printPostorderTraversalRecursive(struct BTreeNode *node)
{
	if (node->left != NULL)
		_printPostorderTraversalRecursive(node->left);
	if (node->right != NULL)
		_printPostorderTraversalRecursive(node->right);
	printf("%d ", node->data->data);
}

void printPostorderTraversalRecursive(struct BTree *btree)
{
	_printPostorderTraversalRecursive(btree->root);
	printf("\n");
}

void printInorderTraversalIterative(struct BTree *btree)
{
	struct BTreeNode *stack[1000];
	int top = 0;
	struct BTreeNode *node = btree->root;
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

void printPostorderTraversalIterative(struct BTree *btree)
{
	// struct BTreeNode *stack[1000];
	// int top = 0;
	// struct BTreeNode *node = btree->root;
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

int _isBinarySearchTree(struct BTreeNode *node)
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

int isBinarySearchTree(struct BTree *btree)
{
	return _isBinarySearchTree(btree->root);
}

int _getHeightBTree(struct BTreeNode *node, int height)
{
	int ans = 0;
	if (node->left != NULL)
		ans = max(ans, _getHeightBTree(node->left, height + 1));
	if (node->right != NULL)
		ans = max(ans, _getHeightBTree(node->right, height + 1));
	if (node->left == NULL && node->right == NULL)
		return height;
	return ans;
}

int getHeightBTree(struct BTree *btree)
{
	return _getHeightBTree(btree->root, 1);
}

void _deleteBTree(struct BTreeNode *node)
{
	if (node->left != NULL)
		_deleteBTree(node->left);
	if (node->right != NULL)
		_deleteBTree(node->right);
	deleteBTreeNode(node);
}

void deleteBTree(struct BTree *btree)
{
	_deleteBTree(btree->root);
	free(btree);
}
