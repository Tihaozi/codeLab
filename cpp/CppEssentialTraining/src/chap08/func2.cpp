// madoodia@gmail.com

#include <iostream>

using namespace std;

void func(const string &);

int main(int argc, char **argv)
{
	string s = "really big string with lots of text in it.";
	func(s);
	printf("s is %s\n", s.c_str());
	return 0;
}

void func(const string & s)
{
	cout << "in func() " << s << endl;
}
