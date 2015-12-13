// working.cpp
// author: madoodia@gmail.com

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	string input_str;
	cout << "Type a string: ";
//	cin >> input_str;
	getline(cin, input_str);
	cout << "Input is: " << input_str << endl;
	return 0;
}
