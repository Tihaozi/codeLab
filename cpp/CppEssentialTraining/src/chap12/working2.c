// madoodia@gmail.com
#include <stdio.h>

int main(int argc, char **argv)
{
/*	puts("Hello World");
	puts("Hello World");
	puts("Hello World");*/

	FILE * out = fopen("file.txt", "w");
	fputs("This is a string\n", out);
	fclose(out);

	char s[128];
	FILE * in = fopen("file.txt", "r");
	fgets(s, 128, in);
	fclose(in);
	printf(s);
	return 0;
}
