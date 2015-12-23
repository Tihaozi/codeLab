// madoodia@gmail.com

#include <iostream>
#include <vector>
#include "animal.h"
using namespace std;

int main(int argc, char *argv[])
{
	int ia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> iv(ia, ia + (sizeof(ia) / sizeof(int)));

	for(int & i : ia) ++i;
	for(int i : ia){
		cout << i << " ";
	}
	cout << endl;

	for(int & i : iv) i *= 5;;
	for(int i : iv){
		cout << i << " ";
	}
	cout << endl;

	for(int i : {3, 5, 7, 9, 11}){
		cout << i << " ";
	}
	cout << endl;

	Dog a("Arnie");
	Dog b("Barky");
	Dog c("Rover");

	for(Dog * d : {&a, &b, &c}){
		d->speak();
		cout << d->name() << endl;
	}

	return 0;
}
