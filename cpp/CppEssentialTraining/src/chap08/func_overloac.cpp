// madoodia@gmail.com

#include <iostream>

using namespace std;

int volume(int s)
{
	cout << "cube of " << s << endl;
	return s * s * s;
}

double volume(double r, int h)
{
	cout << "cylinder of " << r << "x" << h << endl;
	return 3.14159 * r * r * h;
}

long volume(long a, long b, long c)
{
	cout << "cuboid of " << a << "x" << b << "x" << c << endl;
	return a * b * c;
}


int main(int argc, char ** argv)
{
	cout << "volume of a 2x2x2 cube: " << volume(2) << endl;
	cout << "volume of a cylinder, radius 2, height 2: " << volume(2.0, 2) << endl;
	cout << "volume of a 2x3x4 cuboid: " << volume(2, 3, 4) << endl;
	return 0;
}
