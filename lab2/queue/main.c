#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main()
{
	struct Queue *queue = initQueue();

	printf("Output 1\n");
	pushQueue(queue, 1);
	pushQueue(queue, 2);
	pushQueue(queue, 3);
	pushQueue(queue, 4);
	printQueue(queue);

	printf("\nOutput 2\n");
	popQueue(queue);
	popQueue(queue);
	printQueue(queue);

	pushQueue(queue, 5);
	printf("\n%d\n\n", frontQueue(queue));

	printf("\nOutput 3\n");
	popQueue(queue);
	popQueue(queue);
	popQueue(queue);
	printQueue(queue);

	printf("\nOutput 4\n");
	pushQueue(queue, 6);
	printQueue(queue);

	emptyQueue(queue);
	free(queue);
	return 0;
}