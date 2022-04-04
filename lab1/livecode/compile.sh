gcc -c match.c
echo "match.c compiled"
gcc -c main.c
echo "main.c compiled"
gcc match.o main.o -o tournament.out
echo "tournament compiled"
