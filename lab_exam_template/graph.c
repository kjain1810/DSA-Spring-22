#include <stdio.h>
#include <stdlib.h>

// 0 indexed graph with adjacency list
struct Graph {
  int nodes;
  int edges;
  int **adjList;
  int *indegree;
  int *outdegree;
  int directed;
};

typedef struct Graph Graph;

Graph *create_graph(int n, int m, int **edges, int directed) {
  // n -> number of nodes
  // m -> number of edges
  // edges -> list of all edges in an array of dimensions [m][2]
  // directed -> flag whether graph is directed or not
  Graph *G = (Graph *)malloc(sizeof(Graph));
  G->directed = directed;
  G->indegree = (int *)malloc(n * sizeof(int));
  G->outdegree = (int *)malloc(n * sizeof(int));
  for (int a = 0; a < m; a++) {
    G->indegree[edges[a][1]]++;
    G->outdegree[edges[a][0]]++;
    if (!directed) {
      G->indegree[edges[a][0]]++;
      G->outdegree[edges[a][1]]++;
    }
  }
  G->adjList = (int **)malloc(n * sizeof(int *));
  for (int a = 0; a < n; a++)
    G->adjList[a] = (int *)malloc(G->outdegree[a] * sizeof(int));
  int *ptr = (int *)malloc(n * sizeof(int));
  for (int a = 0; a < n; a++)
    ptr[a] = 0;
  for (int a = 0; a < m; a++) {
    G->adjList[edges[a][0]][ptr[edges[a][0]]] = edges[a][1];
    ptr[edges[a][0]]++;
    if (!directed) {
      G->adjList[edges[a][1]][ptr[edges[a][1]]] = edges[a][0];
      ptr[edges[a][1]]++;
    }
  }
  return G;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int **edges = (int **)malloc(m * sizeof(int *));
  for (int a = 0; a < m; a++) {
    edges[a] = (int *)malloc(2 * sizeof(int));
    scanf("%d%d", &edges[a][0], &edges[a][1]);
  }
  Graph *G_directed = create_graph(n, m, edges, 1);
  Graph *G_undirected = create_graph(n, m, edges, 1);
  return 0;
}
