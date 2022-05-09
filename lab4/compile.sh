gcc -c tree.c
gcc -c queue.c
gcc -c $1.c
gcc tree.o queue.o $1.o -o $1
