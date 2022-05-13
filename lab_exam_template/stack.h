#ifndef STACK_H
#define STACK_H

struct StackNode {
  int data;
  struct StackNode* next;
};

struct Stack {
  int size;
  struct StackNode *top;
};

struct StackNode* getStackNode(int data);
int push(struct Stack *stack, struct StackNode* node);
int pop(struct Stack *stack);
struct StackNode* top(struct Stack* stack);

#endif
