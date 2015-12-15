// Advanced Programming
// Instructor: Ramtin Khosravi
// 2015-2016
// madoodia@gmail.com

#include <iostream>
#include <string>

using namespace std;

int main()
{
	float inch;
	float cm;
	cout << "Please enter your inch number: ";
	cin >> inch;
	cm = inch * 2.54;
	cout << "Equivalent of  " << inch << " (inch) is " << cm << " (cm)." << endl;
	return 0;
}
