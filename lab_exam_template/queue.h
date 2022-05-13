#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode {
  int data;
  struct QueueNode* next;
};

struct Queue {
  int size;
  struct QueueNode* first;
  struct QueueNode* last;
};

struct QueueNode* getQueueNode(int data);
int pushQueue(struct Queue *queue, struct QueueNode* node);
int popQueue(struct Queue *queue);
struct QueueNode* frontQueue(struct Queue* queue);
int isQueueEmpty(struct Queue* queue);

#endif
