#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "queue.h"

int isQueueEmpty(struct Queue *queue)
{
	return ((queue->head == NULL) ? 1 : 0);
}

void pushQueue(struct Queue *queue, int num)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (isQueueEmpty(queue))
		queue->head = queue->tail = new_node;
	else
	{
		queue->tail->next = new_node;
		new_node->prev = queue->tail;
		queue->tail = queue->tail->next;
	}
	++queue->size;
}

int popQueue(struct Queue *queue)
{
	if (isQueueEmpty(queue))
	{
		perror("cannot pop elements from empty queue");
		return -1;
	}
	int val = queue->tail->data;
	struct Node *head = queue->head;
	if (queue->head == queue->tail)
		queue->head = queue->tail = NULL;
	else
	{
		queue->head = queue->head->next;
		queue->head->prev = NULL;
	}
	--queue->size;
	free(head);
	return val;
}

int frontQueue(struct Queue *queue)
{
	if (isQueueEmpty(queue))
	{
		perror("cannot get front element of an empty queue");
		return -1;
	}
	int val = queue->head->data;
	return val;
}

struct Queue *initQueue()
{
	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
}

void emptyQueue(struct Queue *queue)
{
	while (queue->size > 0)
		popQueue(queue);
}

void printQueue(struct Queue *queue)
{
	struct Node *curr = queue->head;
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}
