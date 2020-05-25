main : main.o BinarySearch.o
	gcc -o main main.o BinarySearch.o

main.o : main.c BinarySearch.h
	gcc -c -g main.c

BinarySearch.o : BinarySearch.c BinarySearch.h
	gcc -c -g BinarySearch.c

