#include <stdio.h>
#include <stdlib.h>

void dfs(int u, int *vis, int *degree, int **adj)
{
  // mark vertex as visited
  vis[u] = 1;
  for(int a = 0; a < degree[u]; a++)
  {
    int v = adj[u][a];
    if(vis[v])
      continue;
    // visit vertex if not visited
    dfs(v, vis, degree, adj);
  }
}

int main()
{
  // n is number of vertices
  // m is number of edges
  int n, m;
  scanf("%d%d", &n, &m);

  // edges is list of edges
  int **edges = (int**) malloc(sizeof(int*) * m);
  for(int a = 0; a < m; a++)
  {
    edges[a] = (int*)malloc(sizeof(int) * 2);
    scanf("%d%d", &edges[a][0], &edges[a][1]);
    // for zero indexing
    edges[a][0]--;
    edges[a][1]--;
  }
  // degree has degree of each edge
  int *degree = (int*) malloc(sizeof(int) * n);
  for(int a = 0; a < m; a++)
  {
    degree[edges[a][0]]++;
    degree[edges[a][1]]++;
  }
  // this is the adjacency list
  int **adj = (int**) malloc(sizeof(int*) * n);
  // size of each list should be equal to the degree of the vertex
  for(int a = 0; a < n; a++)
    adj[a] = (int*) malloc(sizeof(int) * degree[a]);
  // ptr helps insert the vertices into the adjacency list
  int *ptr = (int*) malloc(sizeof(int) * n);
  // vis keeps track of which vertices have been visited
  int *vis = (int*) malloc(sizeof(int) * n);
  for(int a = 0; a < n; a++)
    ptr[a] = vis[a] = 0;
  // making the adjacency list
  for(int a = 0; a < m; a++)
  {
    adj[edges[a][0]][ptr[edges[a][0]]++] = edges[a][1];
    adj[edges[a][1]][ptr[edges[a][1]]++] = edges[a][0];
  }
  
  // counting number of connected components
  int numComponents = 0;
  for(int a = 0; a < n; a++)
  {
    if(vis[a] == 0)
    {
      // start dfs if vertex has not been visited yet
      dfs(a, vis, degree, adj);
      numComponents++;
    }
  }
  printf("%d\n", numComponents);
  return 0;
}
