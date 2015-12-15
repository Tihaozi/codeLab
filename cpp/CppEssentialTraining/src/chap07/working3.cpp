// madoodia@gmail.com

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int i = 10;
	printf("i is %d\n", i);
	printf("i is %d\n", i++);
	printf("i is %d\n", ++i);

	char s1[] = "string";
	char *cp = s1;
	printf("i is %c\n", *cp++);
	printf("i is %c\n", *cp++);
	printf("i is %c\n", *cp++);

	int i1[] = {1, 2, 3, 4, 5, 0};
	int *ip = i1;
	printf("i is %d\n", *ip++);
	printf("i is %d\n", *ip++);
	printf("i is %d\n", *ip++);

	for(int *ip2 = i1;*ip2;++ip2){
		printf("value is %d\n", *ip2);
	}


	return 0;
}
