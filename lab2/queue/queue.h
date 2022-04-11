#include "node.h"

#ifndef QUEUE_H
#define QUEUE_H

struct Queue // Queue Structure
{
	int size;
	struct Node *head, *tail;
};

int isQueueEmpty(struct Queue *);	 // returns 1 if queue is empty and 0 otherwise
void pushQueue(struct Queue *, int); // pushes the given element in the given queue
int popQueue(struct Queue *);		 // pops the element at the front of the given queue, and returns it
int frontQueue(struct Queue *);		 // Returns the element at the front of the given queue

struct Queue *initQueue();		 // Initializes a new queue
void emptyQueue(struct Queue *); // Empties the given queue

void printQueue(struct Queue *); // Prints the queue front to back

#endif