// author: madoodia@gmail.com
// C-Style use of struct

#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct employee{
	int id;
	const char * name;
	const char * role;
}emp_t;

int main(int argc, char **argv)
{
//	struct employee joe = {42, "Joe", "Boss"};
	emp_t joe = {42, "Joe", "Boss"};
//	struct employee *ep = &joe;
	emp_t *ep = &joe;

	printf("%s is the %s and has id %d\n",
			joe.name, joe.role, joe.id);

	printf("%s is the %s and has id %d\n",
			ep->name, ep->role, ep->id);

	return 0;
}
