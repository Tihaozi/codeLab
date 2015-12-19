#include <iostream>
#include "class1.h"

using namespace std;

int main(int argc, char *argv[])
{
	int i = 47;
	Class1 object1;

	object1.set_value(i);
	cout << "value is " << object1.get_value() << endl;
	return 0;
}
