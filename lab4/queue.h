#include "tree.h"

#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode
{
	struct TreeNode *node;
	struct QueueNode *prev, *next;
};

struct Queue
{
	int size;
	struct QueueNode *front, *back;
};

struct QueueNode *initQueueNode();
void deleteQueueNode(struct QueueNode *node);

struct Queue *initQueue();

int isEmptyQueue(struct Queue *queue);
void enqueue(struct Queue *queue, struct TreeNode *node);
struct TreeNode *dequeue(struct Queue *queue);
struct TreeNode *frontQueue(struct Queue *queue);

void deleteQueue(struct Queue *queue);

#endif