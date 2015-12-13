// working.c
// author: madoodia@gmail.com

#include <stdio.h>

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4

int main(int argc, char **argv)
{
	int foo = 3;
	switch(foo){
	case ONE:
		puts("one");
		break;
	case TWO:
		puts("two");
		break;
	case THREE:
		puts("three");
		break;
	case FOUR:
		puts("four");
		break;
	}
	return 0;
}
