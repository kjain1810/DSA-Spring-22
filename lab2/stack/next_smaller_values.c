#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int a[1001];
int ans[1001];

int main()
{

	int n;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	struct Stack *stack = initStack();

	pushStack(stack, a[0]);
	int near_smaller = -1;
	ans[0] = -1;

	for(int i = 1; i < n; i++){
		int x = popStack(stack);
		while(x >= a[i]){
			x = popStack(stack);
		}
		if(x != -1){
			pushStack(stack, x);
		}
		ans[i] = x;
		pushStack(stack, a[i]);
	}
	
	printf("Answer\n");
	for(int i = 0; i < n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	printStack(stack);

	emptyStack(stack);
	free(stack);
	return 0;
}