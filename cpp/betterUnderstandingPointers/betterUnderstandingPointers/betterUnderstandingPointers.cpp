// betterUnderstandingPointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


class CTest {
public:
	CTest() { printf("CTest constructor\n"); }
	~CTest() { printf("CTest destructor\n"); }
};

void runTest()
{
	CTest test;
	CTest *ptest = new CTest;
	delete ptest;
}

int main()
{
	int i = 1;
	printf("    i : %8.x (value)\n", i);
	printf("   &i : %8.x (address)\n", &i);

	int *p = &i;
	printf("    p : %8.x (value)\n", p);
	printf("   &p : %8.x (address)\n", &p);
	printf("   *p : %8.x (indirection)\n", *p);

	int &r = i;
	printf("    r : %8.x (value)\n", r);
	printf("   &r : %8.x (address)\n", &r);

	int **pp = &p;
	printf("   pp : %8.x (value)\n", pp);
	printf("  &pp : %8.x (address)\n", &pp);
	printf("  *pp : %8.x (indirection)\n", *pp);
	printf(" **pp : %8.x (double indirection)\n", **pp);

	*p = 2;
	printf("    i : %8.x (value)\n", i);
	**pp = 3;
	printf("    i : %8.x (value)\n", i);
	
	printf("\n\n------------------------------------\n\n");
	

	char str[] = "This is a string";

	char *sp = str;

	printf("    str : \"%s\"\n", str);
	printf("    str : %8.x (address)\n", str);
	printf("   *str : %8.x (indirection)\n", *str);
	printf("     sp : %8.x (value)\n", sp);
	printf("    *sp : %8.x (indirection)\n", *sp);

	sp[4] = '1';
	printf("    str : \"%s\"\n", str);

	*(sp + 4) = '2';
	printf("    str : \"%s\"\n", str);

	printf("\n\n------------------------------------\n\n");

	runTest();



	getc(stdin);
    return 0;
}

