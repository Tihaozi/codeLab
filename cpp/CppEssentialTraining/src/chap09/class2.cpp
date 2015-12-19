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
	void look_at_this(int i);
};

void Class1::look_at_this(int i)
{
	printf("i is %d\n", i);
	printf("i is %d\n", this->i);
	printf("this is %p\n", this);
}

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
	object1.look_at_this(13);
	printf("object1 is %p\n", &object1);
	cout << "value is " << object1.get_value() << endl;
	return 0;
}
