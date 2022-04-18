#include <stdlib.h>
#include "tree_data.h"

struct TreeData *createDataInstance(int data)
{
	struct TreeData *tree_data = (struct TreeData *)malloc(sizeof(struct TreeData));
	tree_data->data = data;
	return tree_data;
}

void deleteDataInstance(struct TreeData *data)
{
	free(data);
}