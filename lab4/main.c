#include <stdio.h>
#include "tree.h"

typedef struct TreeData data;
typedef struct TreeNode node;
typedef struct Tree tree;

int main()
{
	int n;
	scanf("%d", &n);
	node *nodes[n];
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		nodes[i] = initTreeNode();
		nodes[i]->data->val = arr[i];
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		addChildTreeNode(nodes[--x], nodes[--y]);
	}
	tree *my_tree = initTree();
	my_tree->root = nodes[0];
	my_tree->size = n;

	printLevelOrderTraversalTree(my_tree);
	printf("--------------------------------------------------------------------\n");
	for (int i = 1; i <= 4; ++i)
	{
		printf("Level %d: ", i);
		printKthLevelTree(my_tree, i);
	}

	deleteTree(my_tree);
	return 0;
}