// madoodia@gmail.com
#pragma once
#include <iostream>
using namespace std;

// base class
class Animal {
	string _name;
	string _type;
	string _sound;
protected:
	// private constructor prevents construction of base class
	Animal(){};
	// protected constructor for use by derived class
	Animal(const string & n, const string & t, const string & s) : _name(n), _type(t), _sound(s){};

public:
	virtual void speak() const; // important (virtual)
	const string & name() const;
	const string & type() const;
	const string & sound() const;
	virtual ~Animal(){}
};

// Dog class - derived from Animal
class Dog : public Animal {
	int walked;
public:
	Dog(string n) : Animal(n, "dog", "woof"), walked(0){};
	int walk();
};
