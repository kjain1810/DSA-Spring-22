#ifndef TREE_H
#define TREE_H

struct TreeData // Tree node data.
{
	int val;
};

struct TreeNode // Tree node.
{
	struct TreeData *data;
	struct TreeNode *child, *last_child, *next, *prev;
};

struct Tree // Tree
{
	int size;
	struct TreeNode *root;
};

struct TreeData *createDataInstance(int val);
void printData(struct TreeData *data);
void deleteDataInstance(struct TreeData *data);

struct TreeNode *initTreeNode();
void addChildTreeNode(struct TreeNode *parent, struct TreeNode *child);
void deleteChildTreeNode(struct TreeNode *parent);
void deleteTreeNode(struct TreeNode *tree_node);

struct Tree *initTree();
void printLevelOrderTraversalTree(struct Tree *tree);
void printKthLevelTree(struct Tree *tree, int k);
void deleteTree(struct Tree *tree);

#endif