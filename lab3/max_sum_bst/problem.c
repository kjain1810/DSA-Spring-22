#include <stdio.h>
#include <stdlib.h>
#include "tree_data.h"
#include "tree_node.h"
#include "tree.h"

typedef struct TreeData treeData;
typedef struct TreeNode treeNode;
typedef struct Tree tree;

int maxSumBST(tree *t)
{
	// Your implementation
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	tree *my_tree = generateTree(n, arr);

	printf("%d\n", maxSumBST(my_tree));

	deleteTree(my_tree);
	return 0;
}