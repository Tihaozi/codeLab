// working.c
// author: madoodia@gmail.com

#include <stdio.h>

#define ADD_MACRO(a, b) (a + b)

int main(int argc, char **argv)
{
	int this = 5;
	int that = 13;
	printf("this: %d, that: %d, result: %d\n", this, that, ADD_MACRO(this, that));
	return 0;
}
