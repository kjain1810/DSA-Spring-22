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
    return find_set(parent[v]);
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
    union_sets(1, 2);
    printf("%d ", find_set(0));
    printf("%d ", find_set(1));
    printf("%d ", find_set(2));
    

    return 0;
}