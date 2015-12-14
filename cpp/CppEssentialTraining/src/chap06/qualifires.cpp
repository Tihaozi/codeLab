// author: madoodia@gmail.com
// type qualifier: const, volatile, mutable
// storage class: static, register, extern

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv)
{
	int i = 47;
	i = 112;
	const int j = 85;

	printf("The integer is %d\n", i);

	for(int k = 0;k < 5;k++){
		static int l = 12;
		l += k;
		printf("k is %d, l is %d\n", k, l);
	}

	return 0;
}
