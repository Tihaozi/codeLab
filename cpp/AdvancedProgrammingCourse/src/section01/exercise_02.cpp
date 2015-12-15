// Advanced Programming
// Instructor: Ramtin Khosravi
// 2015-2016
// madoodia@gmail.com

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string current = "";
	string result = "[";
	cout << "Please enter a few words (add a 0 to the end): ";
	while(1){
		cin >> current;
		result += current;
		if(current == "0") break;
		result += ", ";
	}
	result += "]";
	cout << "Array is: " << result << endl;
	return 0;
}
