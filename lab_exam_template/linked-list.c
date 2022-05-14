#include <stdio.h>
#include <stdlib.h>

typedef struct LL_Node {
  int val;
  struct LL_Node *next;
} LL_Node;

typedef struct LL {
  int size;
  LL_Node *head;
} LL;

// Initalize and return a pointer to a linked list node
LL_Node *LL_Node_init(int val) {
  LL_Node *n = malloc(sizeof(LL_Node));
  n->val = val;
  n->next = NULL;
  return n;
}

// Initalize and return a pointer to a linked list
LL *LL_init() {
  LL *l = malloc(sizeof(LL));
  l->head = NULL;
  l->size = 0;
  return l;
}

// Returns size of a linked list
int LL_Size(LL *l) { return l->size; }

// Add a value to linked list position p (0 index)
// This means that the node at position p will have value = val
// after this operation
void LL_add(LL *l, int p, int val) {
  LL_Node *n = LL_Node_init(val);
  LL_Node *prev = NULL;
  LL_Node *curr = l->head;
  int i = 0;
  while (i != p) {
    prev = curr;
    curr = curr->next;
    ++i;
  }
  if (prev != NULL) {
    prev->next = n;
  }
  n->next = curr;
  l->size += 1;
}

// Search for a value in a linked list
// Returns 1 if found, 0 if not found
int LL_search(LL *l, int val) {
  LL_Node *curr = l->head;
  while (curr != NULL) {
    if (curr->val == val) {
      return 1;
    }
    curr = curr->next;
  }
  return 0;
}

// Deletes the first value = val from the linked list, 1 for successful
// deletion, 0 for no deletion
int LL_delete(LL *l, int val) {
  LL_Node *curr = l->head;
  LL_Node *prev = NULL;
  while (curr != NULL) {
    if (curr->val == val) {
      if (prev != NULL) {
        prev->next = curr->next;
      } else {
        if (curr->next == NULL) {
          l->head = NULL;
        } else {
          l->head = curr->next;
        }
      }
      free(curr);
      l->size -= 1;
      return 1;
    }
    prev = curr;
    curr = curr->next;
  }
  return 0;
}

// Prints a linked list
void LL_print(LL *l) {
  LL_Node *curr = l->head;
  while (curr != NULL) {
    printf("%d ", curr->val);
    curr = curr->next;
  }
  printf("\n");
}
