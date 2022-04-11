#ifndef STACK_H
#define STACK_H

struct Node {
  int data;
  struct Node* next;
};

struct Stack {
  struct Node* top;
  int size;
};

int push(struct Stack* stack, int data);
int pop(struct Stack* stack);
struct Node* top(struct Stack* stack);

#endif
