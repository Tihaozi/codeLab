// madoodia@gmail.com

#include <iostream>
#include <typeinfo>
using namespace std;

template<typename lhsT, typename rhsT>
auto tf(lhsT lhs, rhsT rhs) -> decltype(lhs + rhs){
	return lhs + rhs;
}

int main(int argc, char *argv[])
{
	int i = 85;
	const char * cstr = "This is a C-string";
	string sclass = string("This is a string class string");

	auto x = string("This is a string class string");
	decltype(x) y;

	cout << "type of i\t: " << typeid(i).name() << endl;
	cout << "type of cstr\t: " << typeid(cstr).name() << endl;
	cout << "type of sclass\t: " << typeid(sclass).name() << endl;
	cout << "type of x\t: " << typeid(x).name() << endl;
	cout << "type of y\t: " << typeid(y).name() << endl;

	for(auto it = sclass.begin(); it != sclass.end();++it){
		cout << *it << " ";
	}
	cout << endl;

	for(auto c : sclass) cout << c << " ";
	cout << endl;

	auto z = tf(sclass, cstr);
	cout << "z is " << z << endl;
	cout << "type of z: " << typeid(z).name() << endl;

	return 0;
}
