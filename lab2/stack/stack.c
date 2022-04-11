#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "stack.h"

int isStackEmpty(struct Stack *stack)
{
	return ((stack->head == NULL) ? 1 : 0);
}

void pushStack(struct Stack *stack, int num)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (isStackEmpty(stack))
		stack->head = stack->tail = new_node;
	else
	{
		stack->tail->next = new_node;
		new_node->prev = stack->tail;
		stack->tail = stack->tail->next;
	}
	++stack->size;
}

int popStack(struct Stack *stack)
{
	if (isStackEmpty(stack))
	{
		perror("cannot pop elements from empty stack");
		return -1;
	}
	int val = stack->tail->data;
	struct Node *tail = stack->tail;
	if (stack->head == stack->tail)
		stack->head = stack->tail = NULL;
	else
	{
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
	}
	--stack->size;
	free(tail);
	return val;
}

int topStack(struct Stack *stack)
{
	if (isStackEmpty(stack))
	{
		perror("cannot get top element of an empty stack");
		return -1;
	}
	int val = stack->tail->data;
	return val;
}

struct Stack *initStack()
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->head = NULL;
	stack->tail = NULL;
	return stack;
}

void emptyStack(struct Stack *stack)
{
	while (stack->size > 0)
		popStack(stack);
}

void printStack(struct Stack *stack)
{
	struct Node *curr = stack->tail;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->prev;
	}
}
