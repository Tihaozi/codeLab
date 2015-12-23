// madoodia@gmail.com

#include <iostream>
using namespace std;

#ifndef NULL
#define NULL 0 	// standard C++ Definition
#endif // NULL

void f(int i){
	printf("the int is %d\n", i);
}

void f(char * s){
	printf("the pointer is %p\n", s);
}

int main(int argc, char *argv[])
{
	// f(NULL); 	// error: call of overloaded 'f(NULL)' is ambiguous
	f(0);
	f(nullptr);
	return 0;
}
