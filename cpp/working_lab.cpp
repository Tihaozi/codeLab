#include <iostream>

using namespace std;

int myAdd(int a, int b)
{
    return a + b;
}

int main(int argc, char **argv)
{
    cout << "result is: " << myAdd(12, 13) << endl;
    return 0;
}