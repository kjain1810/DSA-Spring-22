#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

struct QueueNode *initQueueNode()
{
	struct QueueNode *node = (struct QueueNode *)malloc(sizeof(struct QueueNode));
	node->node = NULL;
	node->prev = node->next = NULL;
	return node;
}

void deleteQueueNode(struct QueueNode *node)
{
	free(node);
}

struct Queue *initQueue()
{
	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->front = queue->back = NULL;
	queue->size = 0;
	return queue;
}

int isEmptyQueue(struct Queue *queue)
{
	return ((queue->front == NULL) ? 1 : 0);
}

void enqueue(struct Queue *queue, struct TreeNode *node)
{
	struct QueueNode *new_node = initQueueNode();
	new_node->node = node;
	new_node->next = new_node->prev = NULL;
	if (isEmptyQueue(queue))
		queue->front = queue->back = new_node;
	else
	{
		queue->back->next = new_node;
		new_node->prev = queue->back;
		queue->back = queue->back->next;
	}
	++queue->size;
}

struct TreeNode *dequeue(struct Queue *queue)
{
	if (isEmptyQueue(queue))
	{
		printf("cannot pop elements from empty queue\n");
		return NULL;
	}
	struct TreeNode *node = queue->front->node;
	struct QueueNode *head = queue->front;
	if (queue->front == queue->back)
		queue->front = queue->back = NULL;
	else
	{
		queue->front = queue->front->next;
		queue->front->prev = NULL;
	}
	--queue->size;
	deleteQueueNode(head);
	return node;
}

struct TreeNode *frontQueue(struct Queue *queue)
{
	if (isEmptyQueue(queue))
	{
		printf("cannot get front element of an empty queue\n");
		return NULL;
	}
	return queue->front->node;
}

void deleteQueue(struct Queue *queue)
{
	while (queue->size > 0)
		dequeue(queue);
}
