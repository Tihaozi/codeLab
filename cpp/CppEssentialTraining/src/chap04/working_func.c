// working_func.c
// author: madoodia@gmail.com

#include <stdio.h>

extern int var;
extern void func();

int main(int argc, char **argv)
{
	func();
	printf("the extern var is: %d\n", var);
	for(int i=0; i < 5;++i){
		static int number = 7;
		printf("number is: %d\n", number++);
	}
	return 0;
}
