#include <stdlib.h>

#include "stack.h"

typedef struct Node NNode;
typedef struct Stack SStack;

int push(struct Stack* stack, int data)
{
  if(stack == NULL)
    return 1;
  NNode* node = (NNode*)malloc(sizeof(NNode));
  node->data = data;
  node->next = stack->top;
  stack->top = node;
  stack->size += 1;
  return 0;
}

int pop(SStack* stack)
{
  if(stack == NULL)
    return 1;
  if(stack->size == 0)
    return 1;
  NNode* temp = stack->top;
  stack->top = stack->top->next;
  stack->size -= 1;
  free(temp);
  return 0;
}

NNode* top(SStack* stack)
{
  if(stack == NULL)
    return NULL;
  return stack->top;
}
