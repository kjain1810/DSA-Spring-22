# Lab Exam Templates

The following code will be provided to the students to use in the lab exams.

## Files
1. bin\_tree.h : ADT for binary trees
2. bin\_tree.c : Implementation of binary tree ADT
3. queue.h : ADT for queues
4. queue.c : Implementation of queue ADT
5. stack.h : ADT for stacks
6. stack.c : Implementation of stack ADT
7. tree.c : ADT for trees
8. tree.h : Implementation of tree ADT
9. copy\_lines.sh : Bash script to copy particular lines from one file to another

### Copy lines
Usage:
```bash
sh ./copy_lines.sh <source_file> <start_line> <end_line> <target_file> <target_line>
```

This command copies lines number between `start_line` and `end_line` in `source_file` to `target_file` starting from line number `target_line`.

Might be useful during the exam :)

### Binary Tree ADT

### Queue ADT
Data members of `QueueNode`:
1. data
2. next

Data members of `Queue`:
1. size
2. first
3. last

Functions:
1. `struct QueueNode* getQueueNode(int data)` : returns a QueueNode with data as `data` and next as `NULL`
2. `int pushQueue(struct Queue *queue, struct QueueNode* node)` : Adds `node` to the back of `queue`
3. `int popQueue(struct Queue *queue)` : Removes the first element of `queue`
4. `struct QueueNode* frontQueue(struct Queue* queue)` : Get the element at the front of `queue`
5. `int isQueueEmpty(struct Queue* queue)` : Check if `queue` is empty

### Stack ADT
Data members of `StackNode`:
1. data
2. next

Data members of `Queue`:
1. size
2. top

Functions:
1. `struct StackNode* getStackNode(int data)` : returns a StackNode with data as `data` and next as `NULL`
2. `int pushStack(struct Stack *stack, struct StackNode* node)`: Adds `node` to the top of `stack`
3. `int popStack(struct Stack *stack)` : Removes top of the stack
4. `struct StackNode* topStack(struct Stack* stack)` : Gets the element at the top of `stack`
5. `int isStackEmpty(struct Stack* stack)` : Checks if `stack` is empty



### Tree ADT

