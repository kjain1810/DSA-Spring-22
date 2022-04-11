#include "node.h"

#ifndef STACK_H
#define STACK_H

struct Stack // Stack Structure
{
	int size;
	struct Node *head, *tail;
};

int isStackEmpty(struct Stack *);	 // returns 1 if stack is empty and 0 otherwise
void pushStack(struct Stack *, int); // pushes the given element in the given stack
int popStack(struct Stack *);		 // pops the element at the top of the given stack, and returns it
int topStack(struct Stack *);		 // Returns the element at the top of the given stack

struct Stack *initStack();		 // Initializes a new stack
void emptyStack(struct Stack *); // Empties the given stack

void printStack(struct Stack *); // Prints the stack top to bottom

#endif