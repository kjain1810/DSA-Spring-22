#include "btree_data.h"

#ifndef BTREE_NODE_H
#define BTREE_NODE_H

struct BTreeNode // Binary Tree node.
{
	struct BTreeData *data;
	struct BTreeNode *left, *right;
};

struct BTreeNode *initBTreeNode();
void deleteBTreeNode(struct BTreeNode *btree_node);

#endif