// madoodia@gmail.com
#include <stdio.h>

int main(int argc, char **argv)
{
	const char * fn = "test.file";
	const static int maxstring = 1024;
	const char * str = "This is a literal C-string.\n";

	// create/write the file
	printf("writing file\n");
	FILE * fw = fopen(fn, "w");
	for(int i = 0;i < 5;i++){
		fputs(str, fw);
	}
	fclose(fw);
	printf("done.\n");

	// read the file
	printf("reading file\n");
	char buf[maxstring];
	FILE * fr = fopen(fn, "r");
	char * rc;
	while((rc = fgets(buf, maxstring, fr))){
		printf(buf);
	}
	fclose(fr);
	printf("done\n");

	return 0;
}
