#include <stdio.h>
#include <stdlib.h>

struct TreeData // Tree node data.
{
	int val;
};

struct TreeNode // Tree node.
{
	struct TreeData *data;
	struct TreeNode *child, *last_child, *next, *prev;
};

struct Tree // Tree
{
	int size;
	struct TreeNode *root;
};

struct TreeData *createDataInstance(int val)
{
	struct TreeData *data = (struct TreeData *)malloc(sizeof(struct TreeData));
	data->val = val;
	return data;
}

void printData(struct TreeData *data)
{
	printf("%d", data->val);
}

void deleteDataInstance(struct TreeData *data)
{
	free(data);
}

struct TreeNode *initTreeNode()
{
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->data = createDataInstance(0);
	node->child = node->last_child = node->next = node->prev = NULL;
	return node;
}

void addChildTreeNode(struct TreeNode *parent, struct TreeNode *child)
{
	if (parent->child == NULL)
		parent->child = parent->last_child = child;
	else
	{
		parent->last_child->next = child;
		child->prev = parent->last_child;
		parent->last_child = parent->last_child->next;
	}
}
struct Tree *initTree()
{
	struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
	tree->size = 0;
	tree->root = NULL;
	return tree;
}
struct TreeData *createDataInstance(int val);
void printData(struct TreeData *data);
void deleteDataInstance(struct TreeData *data);

struct TreeNode *initTreeNode();
void addChildTreeNode(struct TreeNode *parent, struct TreeNode *child);
void deleteChildTreeNode(struct TreeNode *parent);
void deleteTreeNode(struct TreeNode *tree_node);

struct Tree *initTree();


struct QueueNode
{
	struct TreeNode *node;
	struct QueueNode *prev, *next;
};

struct Queue
{
	int size;
	struct QueueNode *front, *back;
};

struct QueueNode *initQueueNode();
void deleteQueueNode(struct QueueNode *node);

struct Queue *initQueue();

int isEmptyQueue(struct Queue *queue);
void enqueue(struct Queue *queue, struct TreeNode *node);
struct TreeNode *dequeue(struct Queue *queue);
struct TreeNode *frontQueue(struct Queue *queue);

void deleteQueue(struct Queue *queue);

struct QueueNode *initQueueNode()
{
	struct QueueNode *node = (struct QueueNode *)malloc(sizeof(struct QueueNode));
	node->node = NULL;
	node->prev = node->next = NULL;
	return node;
}

void deleteQueueNode(struct QueueNode *node)
{
	free(node);
}

struct Queue *initQueue()
{
	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->front = queue->back = NULL;
	queue->size = 0;
	return queue;
}

int isEmptyQueue(struct Queue *queue)
{
	return ((queue->front == NULL) ? 1 : 0);
}

void enqueue(struct Queue *queue, struct TreeNode *node)
{
	struct QueueNode *new_node = initQueueNode();
	new_node->node = node;
	new_node->next = new_node->prev = NULL;
	if (isEmptyQueue(queue))
		queue->front = queue->back = new_node;
	else
	{
		queue->back->next = new_node;
		new_node->prev = queue->back;
		queue->back = queue->back->next;
	}
	++queue->size;
}

struct TreeNode *dequeue(struct Queue *queue)
{
	if (isEmptyQueue(queue))
	{
		printf("cannot pop elements from empty queue\n");
		return NULL;
	}
	struct TreeNode *node = queue->front->node;
	struct QueueNode *head = queue->front;
	if (queue->front == queue->back)
		queue->front = queue->back = NULL;
	else
	{
		queue->front = queue->front->next;
		queue->front->prev = NULL;
	}
	--queue->size;
	deleteQueueNode(head);
	return node;
}

struct TreeNode *frontQueue(struct Queue *queue)
{
	if (isEmptyQueue(queue))
	{
		printf("cannot get front element of an empty queue\n");
		return NULL;
	}
	return queue->front->node;
}

void deleteQueue(struct Queue *queue)
{
	while (queue->size > 0)
		dequeue(queue);
}

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
    minValues[idx] = 1e9;
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
