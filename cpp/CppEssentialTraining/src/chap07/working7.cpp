// madoodia@gmail.com

#include <iostream>
#include <stdio.h>

using namespace std;

int & f(int & i)
{
	puts("this is f()");
	return ++i;
}


int main()
{
	int x = 7;
	int y = 13;
//	printf("value is %d\n", x);
//	printf("value is %d\n", x += y);
//	printf("value is %d\n", x -= y);
//	printf("value is %d\n", x *= y);

	printf("result is %d\n", f(x) += y); // thhis is different than f(x) = f(x) + y;
	printf("x is %d\n", x);
	return 0;
}
