// madoodia@gmail.com

#include <iostream>

using namespace std;

unsigned long int factorial(unsigned long int n)
{
	if(n < 2) return 1;
	return factorial(n - 1) * n;
	// second way (non-recursive)
//	unsigned long int result = n;
//	while(n > 1) result *= --n;
//	return result;
}

int main(int argc, char ** argv)
{
	unsigned long int n = 10;
	cout << "factorial of " << n << " is " << factorial(n) << endl;
	return 0;
}
