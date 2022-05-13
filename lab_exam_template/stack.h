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
int pushStack(struct Stack *stack, struct StackNode* node);
int popStack(struct Stack *stack);
struct StackNode* topStack(struct Stack* stack);
int isStackEmpty(struct Stack* stack);

#endif
