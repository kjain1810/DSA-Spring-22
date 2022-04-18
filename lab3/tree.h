#include "tree_node.h"
#include "tree_data.h"

#ifndef TREE_H
#define TREE_H

struct Tree // Binary Tree.
{
	struct TreeNode *root;
};

struct Tree *initTree();
struct Tree *generateTree(int n, int arr[]); // Use as Blackbox

void printInorderTraversalRecursive(struct Tree *tree);
void printPostorderTraversalRecursive(struct Tree *tree);

void printInorderTraversalIterative(struct Tree *tree);
void printPostorderTraversalIterative(struct Tree *tree);

int isBinarySearchTree(struct Tree *tree);
int getHeightTree(struct Tree *tree);

void deleteTree(struct Tree *tree);

#endif