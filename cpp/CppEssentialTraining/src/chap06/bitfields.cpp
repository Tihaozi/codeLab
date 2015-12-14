// author: madoodia@gmail.com

#include <iostream>
#include <stdio.h>

using namespace std;

struct preferences{
	bool like_music : 1;
	bool has_hair : 1;
	bool has_internet : 1;
	bool has_dianosaur : 1;
	unsigned int number_of_childrens : 4;
};

int main(int argc, char **argv)
{
	struct preferences homer;
	homer.like_music = true;
	homer.has_hair = false;
	homer.has_dianosaur = true;
	homer.has_internet = false;
	homer.number_of_childrens = 3;

	if(homer.like_music) printf("homer likes music\n");
	if(homer.has_hair) printf("homer has hair\n");
	if(homer.has_internet) printf("homer has internet\n");
	if(homer.has_dianosaur) printf("homer has dianosaur\n");
	printf("homer has %d of children(s)\n", homer.number_of_childrens);
	return 0;
}
