// author: madoodia@gmail.com

#include <iostream>
//#include <stdio.h>

using namespace std;

int main(int argc, char **argv)
{
	char string[] = "This is \' \" \\ \u03bc \x40 \n\ta string";

	cout << string << endl;

	return 0;
}
