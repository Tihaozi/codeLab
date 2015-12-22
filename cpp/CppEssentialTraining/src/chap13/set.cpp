// madoodia@gmail.com

#include <iostream>
#include <set>
using namespace std;

int main(int argc, char *argv[])
{
	// from initializer list (C++11)
	cout << "set of strings from initializer list (C++11)" << endl;
	set<string> strset = {"one", "two", "three", "four", "five"};
//	multiset<string> strset = {"one", "two", "three", "four", "five"};
	cout << "size: " << strset.size() << endl;
	for(string s : strset){
		cout << s << " ";
	}
	cout << endl << endl;

	cout << "insert element \"six\": " << endl;
	strset.insert("six");
	for(string s : strset){
		cout << s << " ";
	}
	cout << endl << endl;

	cout << "insert duplicate element \"five\": " << endl;
	pair<set<string>::iterator, bool> rvInsert;
	bool & insertSuccess = rvInsert.second;
	rvInsert = strset.insert("five");
	if(insertSuccess){
		for(string s : strset){
			cout << s << " ";
		}
	} else cout << "insert failed";
	cout << endl << endl;

	cout << "find and erase element \"six\": " << endl;
	set<string>::iterator it = strset.find("six");
	if(it != strset.end()){
		cout << "found " << *it << endl;
		strset.erase(it);
	} else {
		cout << "not found" << endl;
	}
	for(string s : strset){
		cout << s << " ";
	}
	cout << endl << endl;

	return 0;
}
