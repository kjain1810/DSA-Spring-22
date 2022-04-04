CC=gcc
CFLAGS=-I.
DEPS = match.h
OBJ = main.o match.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tournament.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	rm *.out
