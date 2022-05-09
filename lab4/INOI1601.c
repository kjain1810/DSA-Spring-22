#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "tree.h"

typedef struct TreeNode TreeNode;

int min(int a, int b)
{
  if (a < b)
    return a;
  return b;
}

int max(int a, int b)
{
  if(a > b)
    return a;
  return b;
}

int ans = -1e9;

void dfs(TreeNode* node, int* minValues, int* wealth)
{
  int idx = node->data->val;
  /* printf("%d\n", node->data->val); */
  if(node->child == NULL)
  {
    minValues[idx] = wealth[idx];
    return;
  }
  minValues[idx] = 1e9;
  TreeNode* ch = node->child;
  while(ch != NULL)
  {
    dfs(ch, minValues, wealth);
    minValues[idx] = min(minValues[idx], minValues[ch->data->val]);
    minValues[idx] = min(minValues[idx], wealth[ch->data->val]);
    ch = ch->next;
  }
  ans = max(ans, wealth[idx] - minValues[idx]);
  /* printf("%d %d %d\n", idx, wealth[idx], minValues[idx]); */
}

int main()
{
  // declare
  int n;
  TreeNode** nodes;
  int* parent;
  int* wealth;
  int* minValues;

  // input
  scanf("%d", &n);
  parent = (int*) malloc(sizeof(int) * n);
  wealth = (int*) malloc(sizeof(int) * n);
  minValues = (int*) malloc(sizeof(int) * n);
  for(int a = 0; a < n; a++)
    scanf("%d", &wealth[a]);
  for(int a = 0; a < n; a++)
    scanf("%d", &parent[a]);

  // create tree
  nodes = (TreeNode**) malloc(sizeof(TreeNode*) * n);
  for(int a = 0; a < n; a++)
  {
    nodes[a] = initTreeNode();
    nodes[a]->data->val = a;
  }
  int root;
  for(int a = 0; a < n; a++)
  {
    if (parent[a] != -1)
      addChildTreeNode(nodes[parent[a] - 1], nodes[a]);
    else
      root = a;
  }
  /* printf("%d\n", root); */
  dfs(nodes[root], minValues, wealth);
  printf("%d\n", ans);
  return 0;
}
