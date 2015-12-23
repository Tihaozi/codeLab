// madoodia@gmail.com

#include <iostream>
#include "animal.h"
using namespace std;

void Animal::speak() const
{
	printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}
const string & Animal::name() const
{
	return _name;
}
const string & Animal::type() const
{
	return _type;
}
const string & Animal::sound() const
{
	return _sound;
}

int Dog::walk()
{
	return ++walked;
}
