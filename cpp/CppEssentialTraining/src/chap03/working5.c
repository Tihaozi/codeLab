// working.c
// author: madoodia@gmail.com

#include <stdio.h>

int main(int argc, char **argv)
{
	int a = 1;
	int b = 0;
	if(a){
		puts("this is true");
	} else if(b){
		puts("the other is true");
	} else{
		puts("nothing is true");
	}

	int c = (a == 5) ? 7 : 9;
	printf("c is %d\n", c);

	return 0;
}
