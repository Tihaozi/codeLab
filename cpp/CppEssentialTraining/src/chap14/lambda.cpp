// madoodia@gmail.com

#include <iostream>
#include <algorithm>
#include <locale>
using namespace std;

class title {
	char lastc;
public:
	title() : lastc(0){}
	char operator() (char c);
};

char title::operator() (char c){
	if(lastc == ' ' || lastc == 0){
		lastc = c; return toupper(c);
	} else {
		lastc = c; return tolower(c);
	}
}

int main(int argc, char *argv[])
{
	string s = "this is a very big string";

	transform(s.begin(), s.end(), s.begin(), title());

	// using lambda
	char lastc = 0;
	transform(s.begin(), s.end(), s.begin(),
	[&lastc](char c) -> char {
		if(lastc == ' ' || lastc == 0){
			lastc = c; return toupper(c);
		} else {
			lastc = c; return tolower(c);
		}
	});

	cout << s << endl;
	return 0;
}
