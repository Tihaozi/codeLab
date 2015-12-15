// madoodia@gmail.com

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	unsigned int x = 0x50;
	unsigned int y = 0x100;
	printf("%08x %08x %08x\n",x, y, x & y); // and
	printf("%08x %08x %08x\n",x, y, x | y); // or
	printf("%08x %08x %08x\n",x, y, x ^ y); // xor
	printf("%08x %08x %08x\n",x, y, ~x); 	// not
	printf("%08x %08x %08x\n",x, y, x << 4); // shift to left
	printf("%08x %08x %08x\n",x, y, x >> 4); // shift to right

	return 0;
}
