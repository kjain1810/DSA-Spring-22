#include <stdlib.h>
#include "btree_node.h"
#include "btree_data.h"

struct BTreeNode *initBTreeNode()
{
	struct BTreeNode *btree_node = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
	btree_node->data = createDataInstance(0, 0, (int)1e9, -1);
	btree_node->left = btree_node->right = NULL;
	return btree_node;
}

void deleteBTreeNode(struct BTreeNode *btree_node)
{
	deleteDataInstance(btree_node->data);
	free(btree_node);
}
