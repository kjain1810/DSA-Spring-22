#include "queue.h"

#include <stdlib.h>

struct QueueNode* getQueueNode(int data)
{
  struct QueueNode* ret = (struct QueueNode*) malloc(sizeof(struct QueueNode));
  ret->data = data;
  ret->next = NULL;
  return ret;
}

int pushQueue(struct Queue *queue, struct QueueNode *node)
{
  if(queue == NULL)
    return 0;
  if(node == NULL)
    return 0;
  if(queue->size == 0)
  {
    queue->first = queue->last = node;
    queue->size++;
    return 1;
  }
  queue->last->next = node;
  queue->last = node;
  queue->size++;
  return 1;
}

int popQueue(struct Queue *queue)
{
  if (queue == NULL)
    return 0;
  if (queue->size == 0)
    return 0;
  if (queue->size == 1)
  {
    free(queue->first);
    queue->first = queue->last = NULL;
    queue->size--;
    return 1;
  }
  struct QueueNode* node = queue->first;
  queue->first = queue->first->next;
  queue->size--;
  free(node);
  return 1;
}

struct QueueNode* frontQueue(struct Queue* queue)
{
  if(queue == NULL)
    return NULL;
  return queue->first;
}

int isQueueEmpty(struct Queue* queue)
{
  if(queue->size == 0)
    return 1;
  return 0;
}
