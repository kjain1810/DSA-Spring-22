#include <stdio.h>
#include <stdlib.h>

int n, **adj, **edges, *degree;

int main()
{
	scanf("%d", &n);
	adj = (int **)malloc(sizeof(int *) * n);
	edges = (int **)malloc(sizeof(int *) * n);
	for (int a = 1; a < n; a++)
	{
		edges[a] = (int *)malloc(sizeof(int) * 2);
		scanf("%d%d", &edges[a][0], &edges[a][1]);
	}
	degree = (int *)malloc(sizeof(int) * n);
	for (int a = 1; a < n; a++)
	{
		degree[edges[a][0] - 1]++;
		degree[edges[a][1] - 1]++;
	}
	for (int a = 0; a < n; a++)
		adj[a] = (int *)malloc(sizeof(int) * degree[a]);
	int *ptr = (int *)malloc(sizeof(int) * n);
	for (int a = 0; a < n; a++)
		ptr[a] = 0;
	for (int a = 1; a < n; a++)
	{
		adj[edges[a][0] - 1][ptr[edges[a][0] - 1]++] = edges[a][1] - 1;
		adj[edges[a][1] - 1][ptr[edges[a][1] - 1]++] = edges[a][0] - 1;
	}
	printf("Adjacency list:\n");
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < degree[a]; b++)
			printf("%d ", adj[a][b] + 1);
		printf("\n");
	}
	return 0;
}