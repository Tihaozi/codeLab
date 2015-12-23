// madoodia@gmail.com

#include <iostream>
#include <exception>
using namespace std;

class myexception : public exception {
	string s;
public:
	myexception(const char * message) : s(message) {}
	const char * what() const throw();
};

const char * myexception::what() const throw() {
	return s.c_str();
}

const myexception e_ouch("ouch!");
const myexception e_bad("bad code!");
const myexception e_worse("don't do that!");

void broken() {
	cout << "This is a broken function" << endl;
//	throw myexception("ouch!!!");
	throw e_worse;
}

int main(int argc, char *argv[])
{
	try {
		cout << "let's have an emergency!" << endl;
		broken();
	} catch(exception & e) {
		cout << "what(): " << e.what() << endl;
	}
	cout << "This is still running..." << endl;
	return 0;
}
