// madoodia@gmail.com
#include <iostream>
using namespace std;

class A { // data members in class by default are private
	int ia;
	string sb;
	int ic;
public: // create public accessors
	A(const int a, const string & b, const int c) : ia(a), sb(b), ic(c) {};
	void set_a(const int a) {ia = a;}
	void set_b(const string & b) {sb = b;}
	void set_c(const int c) {ic = c;}

	int get_a() const {return ia;}
	const string & get_b() const {return sb;}
	const char * get_b_cstr() const {return sb.c_str();}
	int get_c() const {return ic;}
};

int main(int argc, char *argv[])
{
	A a = {1, "two", 3};
	printf("ia: %d, ib: %s, ic: %d\n", a.get_a(), a.get_b_cstr(), a.get_c());
	return 0;
}
