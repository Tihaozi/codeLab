// madoodia@gmail.com

#include <iostream>
#include <stdio.h>

using namespace std;

struct s{
	int i;
	int j;
	int k;
};

int main()
{
	int i, j, k;
	i = 5;
	k = j = i;
	cout << "i is" << i << endl;
	cout << "j is" << j << endl;
	cout << "k is" << k << endl;

	struct s s1 = {1, 2, 3};
	struct s s2, s3;
	s3 = s2 = s1;
	printf("s1: i is %d, j is %d, k is %d\n", s1.i, s1.j, s1.k);
	printf("s2: i is %d, j is %d, k is %d\n", s2.i, s2.j, s2.k);
	printf("s3: i is %d, j is %d, k is %d\n", s3.i, s3.j, s3.k);
	return 0;
}
