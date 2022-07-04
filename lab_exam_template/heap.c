#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

typedef struct heap_s {
    int capacity;
    int size;
    // a heap of pairs (A, B)
    // arr[size][0] data item A
    // arr[size][1] data item B
    int** arr;
} heap_t;

struct Item {
    int a;
    int b;
};

heap_t* init(int);
void insert(heap_t*, int, int);
int* top(heap_t*);
void pop(heap_t*);
bool empty(heap_t*);

// sorted by data item A asc
int cmp_A(const void *s1, const void *s2)
{
  struct Item *e1 = (struct Item *)s1;
  struct Item *e2 = (struct Item *)s2;
        
  return e1->a > e2->a;
}

heap_t* init(int max)
{
    heap_t* heap = (heap_t*)malloc(sizeof(heap_t));
    heap->capacity = max;
    heap->size = 0;
    heap->arr = (int**)malloc(sizeof(int*) * (max + 1));
    return heap;
}

bool empty(heap_t* heap) { return heap->size == 0; }
int* top(heap_t* heap) { return heap->arr[1]; }

// return true if data1 < data2
bool cmp(int* data1, int* data2) { 
    int b1 = data1[1];
    int b2 = data2[1];
    return b1 < b2; 
}

void swap(int** a, int i, int j)
{
    int* tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void insert(heap_t* heap, int val, int length)
{
    int* node = (int*)malloc(sizeof(int) * 2);
    node[0] = val, node[1] = length;
    heap->arr[++heap->size] = node;
    for (int i = heap->size; i > 1 && cmp(heap->arr[i], heap->arr[i / 2]); i /= 2)
        swap(heap->arr, i, i / 2);
}
void pop(heap_t* heap)
{
    heap->arr[1] = heap->arr[heap->size--];
    for (int i = 1; i * 2 <= heap->size;) {
        // find smaller child to compare with the current node
        int child = cmp(heap->arr[i * 2], heap->arr[i * 2 + 1]) ? i * 2 : i * 2 + 1;
        if (cmp(heap->arr[child], heap->arr[i])) {
            // swap if child is smaller
            swap(heap->arr, child, i);
            i = child;
        } else
            break;
    }
}

int main() {
    int n = 4;
    heap_t* heap = init(n);
    struct Item items[n];
    items[0].a = 3;
    items[0].b = 2;
    items[1].a = 1;
    items[1].b = 7;
    items[2].a = 4;
    items[2].b = 2;
    items[3].a = 3;
    items[3].b = 6;
    for (int i = 0; i < n; ++i)
        insert(heap, items[i].a, items[i].b);

    // sorts items in increasing order of data item A
    printf("qsort:\n");
    qsort(items, n, sizeof(int*), cmp_A);
    for (int i = 0; i < n; ++i)
        printf("%d %d\n", items[i].a, items[i].b);

    printf("heapsort:\n");

    // sorts items in increasing order of data item B
    while (!empty(heap)) {
        printf("%d %d\n", top(heap)[0], top(heap)[1]);
        pop(heap);
    }
    return 0;
}  
    