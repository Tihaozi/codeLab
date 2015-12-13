// working.c
// author: madoodia@gmail.com

#include <stdio.h>

const int iOne = 1;
const int iTwo = 2;
const int iThree = 3;
const int iFour = 4;

int main(int argc, char **argv)
{
	int foo = 6;
	switch(foo){
	case iOne:
		puts("one");
		break;
	case iTwo:
		puts("two");
		break;
	case iThree:
		puts("three");
		break;
	case iFour:
		puts("four");
		break;
	default:
		puts("default");
		break;
	}
	return 0;
}
