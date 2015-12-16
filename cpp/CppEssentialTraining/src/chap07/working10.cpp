// madoodia@gmail.com
// working with ternary conditional operator

#include <iostream>

using namespace std;

struct S{
	int a;
	int b;
	char c;
	char d;
	long int e;
	long int f;
};

int main(int argc, char *argv[])
{
	int i;
	struct S s;
	printf("size of i is %d\n", sizeof(i));
	printf("size of i is %d\n", (int) sizeof(size_t));
	printf("size of i is %d\n", (int) sizeof(i));
	printf("size of i is %d\n", (int) sizeof(int));

	printf("size of i is %d\n", (int) sizeof(s));
	return 0;
}
