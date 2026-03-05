CC = gcc
#CFLAGS = 

build: visu.o

visu.o: src/visu.h
	$(CC) -c src/visu.c -o visu.o

test: visu.o
	$(CC) test/main.c visu.o -o test/main
	./test/main

clean:
	rm -f visu.o