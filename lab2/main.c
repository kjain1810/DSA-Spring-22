#include <stdio.h>

#include "stack.h"

const int N = 1e5 + 5;

typedef struct Stack stack;

int main()
{
  int arr[N], ans[N];
  int n;

  scanf("%d", &n);
  for(int a = 0; a < n; a++)
  {  
    scanf("%d", &arr[a]);
    ans[a] = -1;
  }  
  stack* s;
  for(int a = 0; a < n; a++)
  {
    while(s->size > 0 && arr[top(s)->data] < arr[a])
    { 
      ans[top(s)->data] = a;
      pop(s);
    }
    push(s, a);
  }
  for(int a = 0; a < n; a++)
  {
    if(ans[a] == -1)
      printf("-1 ");
    else
      printf("%d ",arr[ans[a]]);
  }
  printf("\n");
  return 0;
}
