#ifndef QUEUE_H
#define QUEUE_H

struct Node {
  int data;
  struct Node* next;
};

struct Queue {
  struct Node* head;
  struct Node* tail;
  int size;
};

int push(struct Queue*, int );
int pop(struct Queue*);
int front(struct Queue*);
int back(struct Queue*);

#endif
