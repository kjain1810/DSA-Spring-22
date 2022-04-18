#include <stdio.h>
#include <stdlib.h>
#include "tree_data.h"
#include "tree_node.h"
#include "tree.h"

typedef struct TreeData treeData;
typedef struct TreeNode treeNode;
typedef struct Tree tree;

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	tree *my_tree = generateTree(n, arr);
	// printf("here\n");

	// printInorderTraversalRecursive(my_tree);
	// printInorderTraversalIterative(my_tree);
	// printPostorderTraversalRecursive(my_tree);
	// printPostorderTraversalIterative(my_tree);

	printf("%d\n", getHeightTree(my_tree));

	// if (isBinarySearchTree(my_tree))
	// 	printf("It is a BST\n");
	// else
	// 	printf("It is not a BST\n");

	deleteTree(my_tree);
	return 0;
}