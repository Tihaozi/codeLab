// madoodia@gmail.com

#include <iostream>

using namespace std;

void func1(int);
void func2(int *);
void func3(int &);

int main(int argc, char **argv)
{
	int i = 13;
	func1(i);
	func2(&i);
	func3(i);
	printf("i is %d\n", i);
	return 0;
}

void func1(int x)
{
	x = 85;
	printf("in func1() x is %d\n", x);
}
void func2(int * x)
{
	*x = 85;
	printf("in func2() x is %d\n", *x);
}
void func3(int & x)
{
	x = 85;
	printf("in func3() x is %d\n", x);
}
