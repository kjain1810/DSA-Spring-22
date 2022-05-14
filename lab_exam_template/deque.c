#include <stdio.h>
#include <stdlib.h>

typedef struct Deque_Node {
  int val;
  struct Deque_Node *next, *prev;
} Deque_Node;

typedef struct Deque {
  int size;
  Deque_Node *back, *front;
} Deque;

// Initalize and return pointer to a deque node
Deque_Node *Deque_Node_init(int val) {
  Deque_Node *n = malloc(sizeof(Deque_Node));
  n->val = val;
  n->next = n->prev = NULL;
  return n;
}

// Initalize and return pointer to a deque
Deque *Deque_init() {
  Deque *d = malloc(sizeof(Deque));
  d->size = 0;
  d->front = d->back = NULL;
  return d;
}

// Return size of Deque
int Deque_size(Deque *d) { return d->size; }

// 1 if deque is empty, 0 otherwise
int Deque_empty(Deque *d) { return d->size == 0; }

// Returns the element at the front of the deque
int Deque_front(Deque *d) { return d->front->val; }

// Returns the element at the back of the deque
int Deque_back(Deque *d) { return d->back->val;}

// Adds an element at the back of the deque
void Deque_push_back(Deque *d, int val) {
   Deque_Node *n = Deque_Node_init(val);
   if (d->front == NULL) {
      d->front = d->back = n;
   } else {
     d->back->next = n;
     n->prev = d->back;
     d->back = n;
   }
   d->size += 1;
}

// Adds an element at the front of the deque
void Deque_push_front(Deque *d, int val) {
  Deque_Node *n = Deque_Node_init(val);
  if (d->front == NULL) {
    d->front = d->back = n;
  } else {
    d->front->prev = n;
    n->next = d->front;
    d->front = n;
  }
  d->size += 1;
}

// Removes element from back of the deque
void Deque_pop_back(Deque *d) {
  if (d->front == d->back) {
    free(d->front);
    d->front = d->back = NULL;
  } else {
    Deque_Node *new_back = d->back->prev;
    free(d->back);
    d->back = new_back;
    d->back->next = NULL;
  }
  d->size -= 1;
}

// Removes element from the front of the deque
void Deque_pop_front(Deque *d) {
  if (d->front == d->back) {
    d->front = d->back = NULL;
  } else {
    Deque_Node *new_front = d->front->next;
    free(d->front);
    d->front = new_front;
    d->front->prev = NULL;
  }
  d->size -= 1;
}
