// madoodia@gmail.com
#include <iostream>
using namespace std;

class A {
	int ia;
public:
	void set_a(const int a) {ia = a;}
	int get_a();
	int get_a() const; // const safe
};


int A::get_a()
{
	cout << "this is mutable get_a()" << endl;
	return ia;
}

int A::get_a() const
{
	cout << "this is const get_a()" << endl;
	return ia;
}

int main(int argc, char *argv[])
{
	A a;
	a.set_a(13);
	const A b = a;
//	b.set_a(19); // give error because b is const
	cout << a.get_a() << endl;
	cout << b.get_a() << endl;
	return 0;
}
