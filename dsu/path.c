#include <stdio.h>

#define MAX_SETS 1000

int parent[MAX_SETS];
int size[MAX_SETS];

void make_set(int v) {
    parent[v] = v;
    printf("Creating set %d.\n", v);
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}



int main()
{
    for(int i = 0; i < 5; i++){
        make_set(i);
    }
    

    return 0;
}