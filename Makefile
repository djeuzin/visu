CC = gcc
#CFLAGS = 

build: visu.o

visu.o: src/visu.h
	gcc -c src/visu.c -o visu.o

test: visu.o
	gcc test/main.c visu.o -o test/main
	./test/main

clean:
	rm -f visu.o