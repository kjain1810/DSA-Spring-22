#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{
	struct Stack *stack = initStack();

	printf("Output 1\n");
	pushStack(stack, 1);
	pushStack(stack, 2);
	pushStack(stack, 3);
	pushStack(stack, 4);
	printStack(stack);

	printf("\nOutput 2\n");
	popStack(stack);
	popStack(stack);
	printStack(stack);

	pushStack(stack, 5);
	printf("\n%d\n\n", topStack(stack));

	printf("\nOutput 3\n");
	popStack(stack);
	popStack(stack);
	popStack(stack);
	printStack(stack);

	printf("\nOutput 4\n");
	pushStack(stack, 6);
	printStack(stack);

	emptyStack(stack);
	free(stack);
	return 0;
}