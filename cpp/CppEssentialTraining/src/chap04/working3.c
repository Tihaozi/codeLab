// working.c
// author: madoodia@gmail.com

#include <stdio.h>

int main(int argc, char **argv)
{
	for(int i=0; i <= 5;++i){
		static int number = 7;
		printf("number is: %d\n", number++);
	}
	return 0;
}
