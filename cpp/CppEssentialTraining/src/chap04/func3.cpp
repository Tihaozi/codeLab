
// func3.c
// author: madoodia@gmail.com

#include <stdio.h>

// prototype declarations HERE
void func();
int func2();
int func3(int);
int func4(int&);

int main(int argc, char **argv)
{
	func();
	printf("Returned Value is %d\n", func2());
	int res = func3(50);
	printf("Returned Value is %d\n", res);
	int y = 100;
	int res2 = func4(y);
	printf("Returned Value is %d\n", res2);

	return 0;
}

// function definitions
void func()
{
	printf("This is a void function\n");
}
int func2()
{
	int i = 0;
	i += 20;
	return i;
}
int func3(int x)
{
	int i = 0;
	i += x;
	return i;
}
int func4(int& x)
{
	int i = 0;
	i += x;
	return i;
}
