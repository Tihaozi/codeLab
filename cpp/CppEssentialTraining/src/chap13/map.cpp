// madoodia@gmail.com

#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
	// from initializer list (C++11)
	cout << "map of strings, from initializer list (C++11): " << endl;
	// multimap for allowing duplicate elements
	map<string, string> strmap = {
			{"George", "Father"},
			{"Ellen", "Mother"},
			{"Ruth", "Daughter"},
			{"Spike", "Neighbor's Son"}
	};
	map<string, string>::iterator it;

	cout << "size: " << strmap.size() << endl;
	cout << "check a couple of key-value pairs" << endl;
	cout << "Goerge: " << strmap["George"] << endl;
	cout << "Ellen: " << strmap.find("Ellen")->second << endl;
	cout << endl;

	cout << "iterate the map" << endl;
	for(it = strmap.begin();it != strmap.end();it++){
		cout << it->first << "\t: " << it->second << endl;
	}
	cout << endl;

	cout << "insert an element" << endl;
//	strmap.insert(pair<string, string>("Luke", "Neighbor")); // pre-C++11
	strmap.insert({"Luke", "Neighbor"}); 	// initializer list (C++11)
	cout << "inserted, size: " << strmap.size() << endl;
	for(it = strmap.begin();it != strmap.end();it++){
		cout << it->first << "\t: " << it->second << endl;
	}
	cout << endl;

	cout << "insert a duplicate" << endl;
	strmap.insert({"Luke", "Neighbor"}); 	// initializer list (C++11)
	cout << "after an insert, size: " << strmap.size() << endl;
	for(it = strmap.begin();it != strmap.end();it++){
		cout << it->first << "\t: " << it->second << endl;
	}
	cout << endl;

	cout << "find and erase an element" << endl;
	it = strmap.find("Luke");
//	it = strmap.find("Harry"); // not found
	if(it != strmap.end()){
		cout << "found >>> " << it->first << " : " << it->second << endl;
		strmap.erase(it);
		cout << "erased, size: " << strmap.size() << endl;
	} else {
		cout << "not found" << endl;
	}
	for(it = strmap.begin();it != strmap.end();it++){
		cout << it->first << "\t: " << it->second << endl;
	}
	// or
/*	for(auto m : strmap){
		cout << m.first << "\t: " << imsecond << endl;
	}*/
	// or
/*	for(pair<string, string> m : strmap){
		cout << m.first << "\t: " << imsecond << endl;
	}*/

	cout << endl;

	return 0;
}
