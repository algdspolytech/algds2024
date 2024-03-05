CC=gcc
CFLAGS=-Wall

all: main

main: main.o matrix_operations.o
	$(CC)	$(CFLAGS)	-o	main	main.o	matrix_operations.o

main.o: main.c matrix_operations.h
	$(CC)	$(CFLAGS)	-c	main.c

matrix_operations.o: matrix_operations.c matrix_operations.h
	$(CC)	$(CFLAGS)	-c	matrix_operations.c

clean:
	rm	-f	*.o	main
