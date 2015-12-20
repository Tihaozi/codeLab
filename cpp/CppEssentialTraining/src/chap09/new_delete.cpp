// madoodia@gmail.com

#include <iostream>
using namespace std;

class A {
	int _a;
	int _b;
	int _c;
public:
	A(int);
	~A();
	int a() {return _a;}
	int b() {return _b;}
	int c() {return _c;}
};

A::A(int i = 0) : _a(i), _b(i + 1), _c(i + 2)
{
	cout << this << " constructor called" << endl;
}

A::~A()
{
	cout << this << " destructor called" << endl;
}

int main(int argc, char *argv[])
{
	cout << "allocating space for one A object" << endl;
	A * a = new (nothrow) A;
	A * b = new (nothrow) A(5);
	A * c = new (nothrow) A[5];
	if (a == nullptr){
		cerr << "new A failed" << endl;
		return 1;
	}
	printf("a: %d, %d, %d\n", a->a(), a->b(), a->c());
	delete a;
	printf("b: %d, %d, %d\n", b->a(), b->b(), b->c());
	delete b;
	for(int i = 0;i < 5;i++){
		printf("c: %d, %d, %d\n", c[i].a(), c[i].b(), c[i].c());
	}
	delete[] c;
	cout << "space for A object deleted" << endl;
	return 0;
}
