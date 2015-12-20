// madoodia@gmail.com

#include <iostream>

const std::size_t maxlen = 1024;

class MASize {
	std::size_t _size;
public:
//	MASize(std::size_t);	// implicit constructor: size from int
//	MASize(const char *);	// implicit constructor: size from c-string
	explicit MASize(std::size_t);	// explicit constructor: size from int
	explicit MASize(const char *);	// explicit constructor: size from c-string
	std::size_t size() const;
};

MASize::MASize(const std::size_t n)
{
	std::cout << "Constructor: MASize from int" << std::endl;
	_size = (n <= maxlen) ? n : 0;
}

MASize::MASize(const char * s)
{
	std::cout << "Constructor: MASize from c-string" << std::endl;
	for(std::size_t i = 0;i < maxlen;i++){
		if(s[i] == '\0'){
			_size = i;
			return;
		}
	}
	_size = 0;
}

std::size_t MASize::size() const
{
	return _size;
}

using namespace std;

void func(const MASize & s)
{
	cout << "s.size() is " << s.size() << endl;

}

int main(int argc, char *argv[])
{
	//	implicit call
//	MASize s = 'x'; // assign with assignment instead of rantesis means thsis is implicit calling constructor
//	cout << "s.size() is " << s.size() << endl;
//	MASize s2('x');
//	cout << "s2.size() is " << s2.size() << endl;
//	func('x');

	//	explicit call
	MASize s2((size_t) 125); // explicit call
	cout << "s2.size() is " << s2.size() << endl;
	func(MASize("xxxxxx"));
	return 0;
}
