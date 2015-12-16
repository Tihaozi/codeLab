// madoodia@gmail.com
// working with ternary conditional operator
//------------------------------------------------------
// and 	 	&&		and_eq		&=		not_eq 		!=	|
// bitand	&		or_eq 		|=		compl 		~	|
//------------------------------------------------------
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int a = 5;
	int b = 13;
	int c = a bitand b;
//	int c = bitand b; // error
//	int bitand c = b;
	cout << "c is " << c << endl;
	return 0;
}
