// author: madoodia@gmail.com

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv)
{
	string cppstring = "This is a C++ string.";

//	cout << "length of cppstring " << sizeof(cppstring) << endl;
	cout << cppstring << endl;

//	for(unsigned int i = 0;cppstring[i];i++){
//			printf("%02d: %c\n", i, cppstring[i]);
//	}

//	for(unsigned int i = 0;i < cppstring.size();i++){
//		printf("%02d: %c\n", i, cppstring[i]);
//	}

//	for(char c : cppstring){  // for in range
//		printf("%c\n", c);
//	}

	for(auto it = cppstring.begin();it != cppstring.end();++it){
		printf("%c\n", *it);
	}

	return 0;
}
