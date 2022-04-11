#ifndef NODE_H
#define NODE_H

struct Node // Doubly Linked List node.
{
	int data;
	struct Node *next, *prev;
};

#endif