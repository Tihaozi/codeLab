// goto.c
// author: madoodia@gmail.com

#include <stdio.h>

int main(int argc, char **argv)
{
	// goto
	printf("Before the goto.\n");
	goto target;
	printf("After the goto.\n");
	target:
	printf("After the Target.\n");
	// break and continue
	for(int i = 0;i < 10;i++){
		if(i == 4) continue;
		if(i == 8) break;
		printf("i is %d\n", i);
	}
	return 0;
}
