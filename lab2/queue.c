#include <stdlib.h>

#include "queue.h"

typedef struct Queue queue;
typedef struct Node node;

int push(queue* q, int data)
{
  node* n = (node*)malloc(sizeof(node));
  n->data = data;
  n->next = NULL;
  q->tail->next = n;
  q->tail = n;
  q->size += 1;
  return 1;
}

int pop(queue* q)
{
  node* temp = q->head;
  q->head = q->head->next;
  free(temp);
  q->size -= 1;
  return 1;
}

int front(queue* q)
{
  return q->head->data;
}

int back(queue* q)
{
  return q->tail->data;
}
