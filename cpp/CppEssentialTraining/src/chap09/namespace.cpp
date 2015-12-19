// madoodia@gmail.com

#include <iostream>

namespace MAString {
	const std::string mas = "this is MAString::string";
	class string{
		std::string s;
	public:
		string (void) : s(mas){};
		string (const std::string & _s) : s(mas){};
		operator std::string & (void) {return s;};
	};
}; // namespace MAString

using std::cout;

MAString::string s1("This is a string");

int main(int argc, char *argv[])
{
	std::string s = s1;
	cout << s << std::endl;
	return 0;
}
