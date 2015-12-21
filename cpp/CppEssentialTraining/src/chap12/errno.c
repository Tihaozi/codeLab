// madoodia@gmail.com
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char ** argv)
{
	printf("errno is: %d\n", errno);
	printf("Erasing file foo.bar\n");
	remove("foo.bar");
	printf("errno is: %d\n", errno);
//	perror("Couldn't erase file\n");
	printf("the error message is: %s\n", strerror(errno));

	return 0;
}
