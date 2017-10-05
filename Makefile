CC = gcc -ggdb -std=c99 -Wall -Werror -O3

all: string_tests.o string_funcs.o alias.o
	$(CC) -o string_tests string_tests.o string_funcs.o alias.o

string_tests.o: string_funcs.h
	$(CC) -c string_tests.c string_funcs.h

string_funcs.o:
	$(CC) -c string_funcs.c

alias.o:
	$(CC) -c alias.c

clean:
	rm *.o

run: all
	./string_tests
