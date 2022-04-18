CC=gcc
CFLAGS=-I.
DEPS = tree_data.h tree_node.h tree.h
OBJ = problem.o tree_data.o tree_node.o tree.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

problem.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	rm *.out