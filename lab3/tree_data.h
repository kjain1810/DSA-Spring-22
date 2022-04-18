#ifndef TREE_DATA_H
#define TREE_DATA_H

struct TreeData // Tree node data.
{
	int is_BST;
	int data;
	int minval, maxval;
};

struct TreeData *createDataInstance(int is_BST, int data, int minval, int maxval);
void deleteDataInstance(struct TreeData *data);

#endif