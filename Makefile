CC = gcc -ggdb -std=c11 -Wall -Werror

all: strings.c
	$(CC) -o strings strings.c

clean:
	rm *.o

run: all
	./strings