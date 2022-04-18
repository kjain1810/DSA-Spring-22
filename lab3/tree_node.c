#include <stdlib.h>
#include "tree_node.h"
#include "tree_data.h"

struct TreeNode *initTreeNode()
{
	struct TreeNode *tree_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	tree_node->data = createDataInstance(0, 0, (int)1e9, -1);
	tree_node->left = tree_node->right = NULL;
	return tree_node;
}

void deleteTreeNode(struct TreeNode *tree_node)
{
	deleteDataInstance(tree_node->data);
	free(tree_node);
}
