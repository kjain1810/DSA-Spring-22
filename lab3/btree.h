#include "btree_node.h"
#include "btree_data.h"

#ifndef BTREE_H
#define BTREE_H

struct BTree // Binary Tree.
{
	struct BTreeNode *root;
};

struct BTree *initBTree();
struct BTree *generateBTree(int n, int arr[]); // Use as Blackbox

void printInorderTraversalRecursive(struct BTree *btree);
void printPostorderTraversalRecursive(struct BTree *btree);

void printInorderTraversalIterative(struct BTree *btree);
void printPostorderTraversalIterative(struct BTree *btree);

int isBinarySearchBTree(struct BTree *btree);
int getHeightBTree(struct BTree *btree);

void deleteBTree(struct BTree *btree);

#endif