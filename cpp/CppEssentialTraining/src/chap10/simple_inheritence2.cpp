// madoodia@gmail.com
// reviewing friendship

#include <iostream>
using namespace std;

// base class
class Animal {
	string _name;
	string _type;
	string _sound;
	// private constructor prevents construction of base class
	Animal(){};
	Animal(const string & n, const string & t, const string & s) : _name(n), _type(t), _sound(s){};

	friend class Dog;
	friend class Cat;
	friend class Pig;
	friend const string & get_animal_name(const Animal &);

public:
	void speak() const;
	const string & name() const {return _name;}
	const string & type() const {return _type;}
	const string & sound() const {return _sound;}
};

void Animal::speak() const
{
	printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal
class Dog : public Animal {
	int walked;
public:
	Dog(string n) : Animal(n, "dog", "woof"), walked(0){};
	int walk() {return ++walked;}
};

// Cat class - derived from Animal
class Cat : public Animal {
	int petted;
public:
	Cat(string n) : Animal(n, "cat", "meow"), petted(0){};
	int pet() {return ++petted;}
};

// Pig class - derived from Animal
class Pig : public Animal {
	int fed;
public:
	Pig(string n) : Animal(n, "pig", "oink"), fed(0){};
	int feed() {return ++fed;}
};

const string & get_animal_name(const Animal & a)
{
	return a._name;
}

int main(int argc, char *argv[])
{
	Dog d("Rover");
	Cat c("Fluffy");
	Pig p("Arnold");

	d.speak();
	c.speak();
	p.speak();

	d.walk();
	d.walk();
	d.walk();

	cout << d.name() << "the dog has been walked " << d.walk() << " times." << endl;
	cout << c.name() << "the cat has been petted " << c.pet() << " times." << endl;
	cout << p.name() << "the pig has been fed " << p.feed() << " times." << endl;

	cout << "The dog is named " << get_animal_name(d) << endl;
	return 0;
}
