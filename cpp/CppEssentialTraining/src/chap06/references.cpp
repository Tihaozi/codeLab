// author: madoodia@gmail.com

#include <iostream>
#include <stdio.h>

using namespace std;

const int & f(int i)
{
	return ++i;
}

int main(int argc, char **argv)
{
	int i = 5;
	printf("i is %d\n", i);
	int &ir = i; // int *ir = &i;
	printf("i is %d\n", i);
	ir = 10; // *ir = 10;
	printf("i is %d\n", i);
	f(i);
	printf("i is %d\n", i);
	// f(i)) = 13; // make error if we have const qualifier in the name of f function

	return 0;
}
