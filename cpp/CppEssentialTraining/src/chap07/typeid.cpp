// madoodia@gmail.com

#include <iostream>
#include <typeinfo>

using namespace std;

struct A{};
struct B{};

int main(int argc, char *argv[])
{
	struct A a1;
	struct A a2;
	struct B b1;
	struct B b2;

	if(typeid(a1) == typeid(struct A)){
		cout << "same" << endl;
	} else {
		cout << "different" << endl;
	}

	cout << typeid(struct B).name() << endl;
	cout << typeid(string).name() << endl;
	cout << typeid(int).name() << endl;
	cout << typeid(float).name() << endl;
	cout << typeid(double).name() << endl;

	return 0;
}
