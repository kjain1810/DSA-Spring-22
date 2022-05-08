#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

struct TreeData *createDataInstance(int val)
{
	struct TreeData *data = (struct TreeData *)malloc(sizeof(struct TreeData));
	data->val = val;
	return data;
}

void printData(struct TreeData *data)
{
	printf("%d", data->val);
}

void deleteDataInstance(struct TreeData *data)
{
	free(data);
}

struct TreeNode *initTreeNode()
{
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->data = createDataInstance(0);
	node->child = node->last_child = node->next = node->prev = NULL;
	return node;
}

void addChildTreeNode(struct TreeNode *parent, struct TreeNode *child)
{
	if (parent->child == NULL)
		parent->child = parent->last_child = child;
	else
	{
		parent->last_child->next = child;
		child->prev = parent->last_child;
		parent->last_child = parent->last_child->next;
	}
}

void deleteChildTreeNode(struct TreeNode *parent)
{
	if (parent->child == NULL)
	{
		printf("No children to delete\n");
		return;
	}
	struct TreeNode *temp = parent->last_child;
	if (parent->child == parent->last_child)
		parent->child = parent->last_child = NULL;
	else
	{
		parent->last_child = parent->last_child->prev;
		parent->last_child->next = NULL;
	}
	deleteTreeNode(temp);
}

void deleteTreeNode(struct TreeNode *node)
{
	deleteDataInstance(node->data);
	free(node);
}

struct Tree *initTree()
{
	struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
	tree->size = 0;
	tree->root = NULL;
	return tree;
}

void printLevelOrderTraversalTree(struct Tree *tree)
{
	struct Queue *q = initQueue();
	enqueue(q, tree->root);
	while (!isEmptyQueue(q))
	{
		struct TreeNode *rt = dequeue(q);
		struct TreeNode *temp = rt->child;
		while (temp != NULL)
		{
			enqueue(q, temp);
			temp = temp->next;
		}
		printData(rt->data);
		printf(" ");
	}
	printf("\n");
	deleteQueue(q);
}

void printKthLevelTree(struct Tree *tree, int k)
{
	struct Queue *q = initQueue();
	int level[tree->size], f = -1, b = 0;
	enqueue(q, tree->root);
	level[b++] = 1;
	while (!isEmptyQueue(q))
	{
		struct TreeNode *rt = dequeue(q);
		struct TreeNode *temp = rt->child;
		int lvl = level[++f];
		while (temp != NULL)
		{
			enqueue(q, temp);
			level[b++] = lvl + 1;
			temp = temp->next;
		}
		if (lvl == k)
		{
			printData(rt->data);
			printf(" ");
		}
	}
	printf("\n");
	deleteQueue(q);
}

void deleteTree(struct Tree *tree)
{
	struct Queue *q = initQueue();
	enqueue(q, tree->root);
	while (!isEmptyQueue(q))
	{
		struct TreeNode *rt = dequeue(q);
		struct TreeNode *temp = rt->child;
		while (temp != NULL)
		{
			enqueue(q, temp);
			temp = temp->next;
		}
		deleteTreeNode(rt);
	}
	free(tree);
	deleteQueue(q);
}
