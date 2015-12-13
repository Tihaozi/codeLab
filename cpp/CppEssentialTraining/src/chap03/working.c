// working.c
// author: madoodia@gmail.com

#include <stdio.h>

int main(int argc, char **argv)
{
	for(int i=0; i <= 5; ++i){
		int x = printf("Hello World!\n") * 5;
		printf("print returned %d\n", x);
	}
	return 0;
}
