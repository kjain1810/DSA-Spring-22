#ifndef BTREE_DATA_H
#define BTREE_DATA_H

struct BTreeData // Tree node data.
{
	int is_BST;
	int data;
	int minval, maxval;
};

struct BTreeData *createDataInstance(int is_BST, int data, int minval, int maxval);
void deleteDataInstance(struct BTreeData *data);

#endif