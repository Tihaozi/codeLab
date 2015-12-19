// madoodia@gmail.com
#include <iostream>

using namespace std;

struct A {
	int ia;
	int ib;
	int ic;
};

class B { // data members in class by default are private
public:
	int ia;
	int ib;
	int ic;
};

class C { // data members in class by default are private
public:
	int ia;
	string sb;
	int ic;
};

int main(int argc, char *argv[])
{
	A a = {1, 2, 3};
	printf("ia: %d, ib: %d, ic: %d\n", a.ia, a.ib, a.ic);
	B b = {1, 2, 3};
	printf("ia: %d, ib: %d, ic: %d\n", b.ia, b.ib, b.ic);
	C c = {1, "two", 3};
	printf("ia: %d, ib: %s, ic: %d\n", c.ia, c.sb.c_str(), c.ic);
	return 0;
}
