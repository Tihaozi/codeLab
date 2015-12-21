// madoodia@gmail.com
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 5;
	long int li = 1234567890L;
	char * s = "this is a string";
//	printf("i: %d, li: %ld, s: %s\n", i, li, s);
//	fprintf(stdout, "i: %d, li: %ld, s: %s\n", i, li, s);
//	fprintf(stderr, "i: %d, li: %ld, s: %s\n", i, li, s);

//	FILE * of = fopen("file.txt", "w");
//	fprintf(of, "i: %d, li: %ld, s: %s\n", i, li, s);
//	fclose(of);

//	char os[1024];
//	sprintf(os, "i: %d, li: %ld, s: %s\n", i, li, s); // using is dangerous
//	puts(os);

	const int bufSize = 10;
	char os[bufSize];
	snprintf(os, bufSize, "i: %d, li: %ld, s: %s\n", i, li, s); // using is safer
	puts(os);

	return 0;
}
