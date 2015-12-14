// working.c
// author: madoodia@gmail.com

#include <stdio.h>

int main(int argc, char **argv)
{
	int x = 5;
	while(x--){
		printf("x is %d\n", x);
//		--x;
	}
	x = 5;
	printf("\n");
	do{
		printf("x is %d\n", x);
//		--x;
	} while(x--);
	return 0;
}
