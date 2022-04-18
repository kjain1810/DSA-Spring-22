gcc -c tree_data.c 
gcc -c tree_node.c 
gcc -c tree.c 
gcc -c main.c
gcc tree_data.o tree_node.o tree.o main.o -o tree