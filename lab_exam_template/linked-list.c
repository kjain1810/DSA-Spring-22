#include <stdlib.h>
#include <stdio.h>

typedef float DataType;

typedef struct LL_Node {
	DataType val;
	struct LL_Node *next;
} LL_Node;

typedef struct LL {
	int size;
	LL_Node *head;
} LL;

// Initalize and return a pointer to a linked list node
LL_Node *LL_Node_init(DataType val) {
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


// 1 if empty, 0 otherwise
int LL_empty(LL *l) {
  return l->size == 0;
}

// Returns size of a linked list
int LL_Size(LL *l) {
	return l->size;
}

// Add a value to linked list position p (0 index)
// This means that the node at position p will have value = val
// after this operation
// p can range from [0, size]
void LL_add(LL *l, int p, DataType val) {
  int i = 0;
  LL_Node *curr = l->head;
  LL_Node *prev = NULL;
  while (i < p) {
    prev = curr;
    curr = curr->next;
    ++i;
  }
  LL_Node *n = LL_Node_init(val);
  if (prev == NULL) {
    n->next = l->head;
    l->head = n;
  } else {
    prev->next = n;
    n->next = curr;
  }
  l->size += 1;
}

// Search for a value in a linked list
// Returns 1 if found, 0 if not found
int LL_search(LL *l, DataType val) {
	LL_Node *curr = l->head;
	while (curr != NULL) {
		if (curr->val == val) {
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

// Deletes the first value = val from the linked list
void LL_delete(LL *l, DataType val) {
	LL_Node *curr = l->head;
	LL_Node *prev = NULL;
	while (curr != NULL) {
		if (curr -> val == val) {
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
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

int main()
{
  return 0;
}
