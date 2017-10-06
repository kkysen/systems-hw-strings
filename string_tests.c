//
// Created by kkyse on 10/4/2017.
//

#include "string_tests.h"

#include <stdio.h>

#include <string.h>

#include "string_funcs.h"

#define FB false

int main() {
    printf("test\n");

    #if (FB)
    make_aliases();
    modify_python_files();
    #endif

    //my_strlen
    printf("\"Hello\" has %zu characters. Should be %zu\n", my_strlen("Hello"), strlen("Hello"));
    printf("\"\" has %zu characters. Should be %zu\n", my_strlen(""), strlen(""));

    //my_strnlen
    printf("\"Hello\" has %zu characters up to 5. Should be %zu\n", my_strnlen("Hello", 5), strnlen("Hello", 5));
    printf("\"Hello\" has %zu characters up to 6. Should be %zu\n", my_strnlen("Hello", 6), strnlen("Hello", 6));
    printf("\"Hello\" has %zu characters up to 70000. Should be %zu\n", my_strnlen("Hello", 70000), strnlen("Hello", 70000));
    printf("\"Hello\" has %zu characters up to 4. Should be %zu\n", my_strnlen("Hello", 4), strnlen("Hello", 4));
    printf("\"\" has %zu characters up to 1. Should be %zu\n", my_strnlen("", 1), strnlen("", 1));

    //my_strcpy
	char strcpy1[] = "Hello";
	char strcpy2[5];
	char strcpy3[6];
	my_strcpy(strcpy2,strcpy1);
	my_strcpy(strcpy3, strcpy2);
    printf("strcpy1: %s \nstrcpy2: %s\n strcpy3: %s\n", strcpy1, strcpy2, strcpy3);
	char strcpy4[] = "Hello";
	char strcpy5[5];
	char strcpy6[6];
	strcpy(strcpy5,strcpy4);
	strcpy(strcpy6, strcpy5);
	printf("Should be...");
	printf("strcpy1: %s \nstrcpy2: %s\n strcpy3: %s\n", strcpy4, strcpy5, strcpy6);

	//my_strncpy
	char strncpy1[] = "Hello";
	char strncpy2[5];
	char strncpy3[3];
	my_strncpy(strncpy2,strncpy1, 6);
	my_strncpy(strncpy3, strncpy2, 3);
    printf("strncpy1: %s \nstrncpy2: %s\n strncpy3: %s\n", strncpy1, strncpy2, strncpy3);
	char strncpy4[] = "Hello";
	char strncpy5[5];
	char strncpy6[3];
	strncpy(strncpy5,strncpy4, 6);
	strncpy(strncpy6, strncpy5, 3);
	printf("Should be...");
	printf("strncpy1: %s \nstrncpy2: %s\n strncpy3: %s\n", strncpy4, strncpy5, strncpy6);

	//my_strcat
	char strcat1[20];
	char strcat2[20];
	strcpy(strcat1, " there!");
	strcpy(strcat2, "Hello");
	char strcat3[50];
	my_strcat(strcat2, strcat1);
	my_strcat(strcat3, strcat2);
	printf("strcat1: %s \nstrcat2: %s\n strcat3: %s\n", strcat1, strcat2, strcat3);
	char strcat4[20];
	char strcat5[20];
	strcpy(strcat4, " there!");
	strcpy(strcat5, "Hello");
	char strcat6[50];
	strcat(strcat5, strcat4);
	strcat(strcat6, strcat5);
	printf("Should be...");
	printf("strcat1: %s \nstrcat2: %s\n strcat3: %s\n", strcat4, strcat5, strcat6);

	//my_strncat
	char strncat1[20];
	char strncat2[20];
	strcpy(strncat1, " there!");
	strcpy(strncat2, "Hello");
	char strncat3[50];
	my_strncat(strncat2, strncat1, 4);
	my_strncat(strncat3, strncat2, 7);
	printf("strncat1: %s \nstrncat2: %s\n strncat3: %s\n", strncat1, strncat2, strncat3);
	char strncat4[20];
	char strncat5[20];
	strcpy(strncat4, " there!");
	strcpy(strncat5, "Hello");
	char strncat6[50];
	strncat(strncat5, strncat4, 4);
	strncat(strncat6, strncat5, 7);
	printf("Should be...");
	printf("strncat1: %s \nstrncat2: %s\n strncat3: %s\n", strncat4, strncat5, strncat6);

	//my_strcmp
	printf("hello vs. hi: %d, should be %d", my_strcmp("hello", "hi"), strcmp("hello", "hi"));
	printf("orange vs. apple: %d, should be %d", my_strcmp("orange", "apple"), strcmp("orange", "apple"));
	//my_strncmp
	//TODO

	//my_strchr
	printf("l is at position %p of hello, should be %p", my_strchr("hello", 'l'), strchr("hello", 'l'));
	printf("h is at position %p of hello, should be %p", my_strchr("hello", 'h'), strchr("hello", 'h'));

	//my_strstr
	//TODO


    return 0;
}


















