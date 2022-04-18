#include <stdlib.h>
#include "tree_data.h"

struct TreeData *createDataInstance(int is_BST, int data, int minval, int maxval)
{
	struct TreeData *tree_data = (struct TreeData *)malloc(sizeof(struct TreeData));
	tree_data->data = data;
	return tree_data;
}

void deleteDataInstance(struct TreeData *data)
{
	free(data);
}