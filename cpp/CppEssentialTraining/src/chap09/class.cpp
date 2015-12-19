// madoodia@gmail.com
// we can implement this class and runniing process in 3three seperate file
// class declaration in Class1.h
// class1's methods definition in Class1.cpp
// main function in class1_launcher.cpp

#include <iostream>
using namespace std;

// a very simple class
class Class1 {
	int i;  // private data mamber (property)
public:
	void set_value(int value);
	int get_value();
};

void Class1::set_value(int value)
{
	i = value;
}

int Class1::get_value()
{
	return i;
}

int main(int argc, char *argv[])
{
	int i = 47;
	Class1 object1;
	object1.set_value(i);
	cout << "value is " << object1.get_value() << endl;
	return 0;
}
