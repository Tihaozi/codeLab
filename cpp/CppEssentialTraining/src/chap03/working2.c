// working.c
// author: madoodia@gmail.com

#include <stdio.h>

enum {max_str = 127};
static char string[max_str + 1] = "";

int main(int argc, char **argv)
{
	printf("Type a string: ");
	fgets(string, max_str, stdin);
	printf("The string is: %s", string);
	return 0;
}
