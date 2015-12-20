// madoodia@gmail.com

#include <iostream>
using namespace std;

template <typename Type>
Type maxof(Type a, Type b)
{
	return (a > b ? a : b);
}

int main(int argc, char *argv[])
{
	cout << maxof(7, 9) << endl;  						// 9
	cout << maxof("aaaa", "baaa") << endl;				// aaaa
	cout << maxof<string>("aaaa", "baaa") << endl;		// baaa
	return 0;
}
