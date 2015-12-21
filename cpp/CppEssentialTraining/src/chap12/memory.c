// madoodia@gmail.com
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
	const static int strSize = 1024;
	const char * source = "This is a string";
	char * string = NULL;

	printf("Allocating space for string.\n");
	string = malloc(strSize * sizeof(char));
//	string = calloc(strSize, sizeof(char));
	if(string == NULL){
		fputs("cannot allocate memory\n", stderr);
		return 1;
	}
	strncpy(string, source, strSize);
	printf("The string is: %s\n", string);

	free(string);
	printf("string space freed.\n");
	string = NULL; // not necessaru, but a good idea

	return 0;
}
