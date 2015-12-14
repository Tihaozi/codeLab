// working.c
// author: madoodia@gmail.com

#include <stdio.h>
#define ONE 1

const int iOne = 1;

int main(int argc, char **argv)
{
	int *ip = &iOne;
	printf("The constant is %d\n", ONE);
	printf("The constant is %d\n", iOne);
	printf("The constant is %d\n", *ip);
	return 0;
}
