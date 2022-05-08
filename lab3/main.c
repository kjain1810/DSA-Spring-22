#include <stdio.h>
#include <stdlib.h>
#include "btree_data.h"
#include "btree_node.h"
#include "btree.h"

typedef struct BTreeData btreeData;
typedef struct BTreeNode btreeNode;
typedef struct BTree btree;

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	btree *my_btree = generateBTree(n, arr);
	// printf("here\n");

	// printInorderTraversalRecursive(my_btree);
	// printInorderTraversalIterative(my_btree);
	// printPostorderTraversalRecursive(my_btree);
	// printPostorderTraversalIterative(my_btree);

	printf("%d\n", getHeightBTree(my_btree));

	// if (isBinarySearchTree(my_btree))
	// 	printf("It is a BST\n");
	// else
	// 	printf("It is not a BST\n");

	deleteBTree(my_btree);
	return 0;
}