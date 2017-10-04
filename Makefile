CC = gcc -ggdb -std=c11 -Wall -Werror

all: strings.o string_funcs.o std_string_funcs.o string_tests.o util.h
	$(CC) -o strings strings.o string_funcs.o std_string_funcs.o string_tests.o util.h

string_funcs.o: string_funcs.h string_funcs.c
	$(CC) -c string_funcs.c

std_string_funcs.o: string_funcs.h std_string_funcs.c
	$(CC) -c std_string_funcs.c

string_tests.o: string_tests.h string_tests.c
	$(CC) -c string_tests.c

strings.o: strings.c
	$(CC) -c strings.c

clean:
	rm *.o

run: all
	./strings