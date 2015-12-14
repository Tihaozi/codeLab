// working.c
// author: madoodia@gmail.com

#include <stdio.h>

int main(int argc, char **argv)
{
	for(int x=5; x; --x){
		printf("x is %d\n", x);
	}
	int ia[] = {1, 2, 3, 4, 5, 0};
	for(int *ip = ia; *ip; ++ip){
		printf("value is %d\n", *ip);
	}

	return 0;
}
