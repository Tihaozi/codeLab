// madoodia@gmail.com

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int i = 5;
	int j = 42;
	printf("result is %d\n", i + j);
	printf("result is %d\n", i - j);
	printf("result is %d\n", i * j);
	printf("result is %d\n", j / i);
	printf("result is %d\n", j % i);

	double k = 5.1;
	double l = 42.2;
	printf("result is %f\n", k + l);
	printf("result is %f\n", k - l);
	printf("result is %f\n", k * l);
	printf("result is %f\n", l / k);
	printf("result is %f\n", k / l);
//	printf("result is %f\n", l % k); // error

	string s1 = "Hello ";
	string s2 = "World!";
	cout << "s1 is " << s1 << endl;
	cout << "s2 is " << s2 << endl;
	cout << "Concattenation is " << s1 + s2 << endl;

	return 0;
}
