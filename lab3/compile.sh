gcc -c btree_data.c 
gcc -c btree_node.c 
gcc -c btree.c 
gcc -c main.c
gcc btree_data.o btree_node.o btree.o main.o -o btree