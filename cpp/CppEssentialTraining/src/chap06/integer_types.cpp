// integer_types.cpp
// author: madoodia@gmail.com

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv)
{
	char c;
//	unsigned char c;
	short int si;
	int i;
	long int li;
	long long int lli;

	cout << "size of char c is " << sizeof(c) << endl;
	cout << "size of short int si is " << sizeof(si) << endl;
	cout << "size of int i is " << sizeof(i) << endl;
	cout << "size of long int li is " << sizeof(li) << endl;
	cout << "size of long long int lli is " << sizeof(lli) << endl;

	li = 12345;
	printf("li is %d\n", li);
	printf("c = 127\n");
	c = 127;
	printf("c is %d\n", c);
	c++;
	printf("after increment, c is %d\n", c);

	return 0;
}
