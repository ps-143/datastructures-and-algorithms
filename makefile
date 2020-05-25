main : main.o BinarySearch.o InsertionSort.o
	gcc -o main main.o BinarySearch.o InsertionSort.o

main.o : main.c BinarySearch.h InsertionSort.h
	gcc -c -g main.c

BinarySearch.o : BinarySearch.c BinarySearch.h
	gcc -c -g BinarySearch.c

InsertionSort.o : InsertionSort.c InsertionSort.h
	gcc -c -g InsertionSort.c
