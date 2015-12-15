// Advanced Programming
// Instructor: Ramtin Khosravi
// 2015-2016
// madoodia@gmail.com

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string previous = "";
	string current;
	while(cin >> current){
		if(previous == current){
			cout << "repeated word: " << current << endl;
		}
		previous = current;
	}
	return 0;
}
