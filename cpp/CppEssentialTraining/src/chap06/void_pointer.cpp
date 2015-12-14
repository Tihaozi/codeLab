// author: madoodia@gmail.com
#include <stdio.h>

void * func(void *);

int main(int argc, char **argv)
{
	printf("this is voide_pointer.cpp");
	const char *cp = "1234";
	int *vp = (int *) func((void *)cp);
	printf("%08x\n", *vp);
	return 0;
}

void * func(void * vp)
{
	return vp;
}
