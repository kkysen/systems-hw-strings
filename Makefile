CC = gcc -ggdb -std=c11 -Wall -Werror

all: string_tests.o string_funcs.o
	$(CC) -o string_tests string_tests.o string_funcs.o

string_tests.o: string_funcs.h
	$(CC) -c string_tests.c string_funcs.h

string_funcs.o:
	$(CC) -c string_funcs.c

clean:
	rm *.o

run: all
	./string_tests