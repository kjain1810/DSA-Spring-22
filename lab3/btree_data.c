#include <stdlib.h>
#include "btree_data.h"

struct BTreeData *createDataInstance(int is_BST, int data, int minval, int maxval)
{
	struct BTreeData *btree_data = (struct BTreeData *)malloc(sizeof(struct BTreeData));
	btree_data->data = data;
	return btree_data;
}

void deleteDataInstance(struct BTreeData *data)
{
	free(data);
}