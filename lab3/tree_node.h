#include "tree_data.h"

#ifndef TREE_NODE_H
#define TREE_NODE_H

struct TreeNode // Binary Tree node.
{
	struct TreeData *data;
	struct TreeNode *left, *right;
};

struct TreeNode *initTreeNode();
void deleteTreeNode(struct TreeNode *tree_node);

#endif