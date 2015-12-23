// madoodia@gmail.com

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string lineno() {
	static int lineint;
	static char linestr[3];
	if(lineint >= 99) lineint = 0;
	sprintf(linestr, "%02d", ++lineint);
	return string(linestr);
}

int main(int argc, char *argv[])
{
	const char * filename = "test.txt";
	string buffer; 	// for read

	// write to the file
	cout << "write to the file..." << endl;
	ofstream ofile(filename);
	ofile << lineno() << " " << "This is the test file." << endl;
	ofile << lineno() << " " << "This is the test file." << endl;
	ofile << lineno() << " " << "This is the test file." << endl;
	ofile.close();

	// read from the file
	cout << "read from the file..." << endl;
	ifstream ifile(filename);
	while(ifile.good()){
		getline(ifile, buffer);
		cout << buffer << endl;
	}
	ifile.close();

	// append to the file
	cout << "append to the file..." << endl;
	fstream afile(filename, fstream::in | fstream::out | fstream::app);
	if(!afile.good()){
		cout << "failed to open" << endl;
		exit(0);
	}
	cout << "current content: " << endl;
	afile.seekg(0, fstream::beg); 	// seek to beginning of file
	while(afile.good()){
		getline(afile, buffer);
		cout << buffer << endl;
	}
	afile.clear(); 	// clear error flags after reading to eof

	cout << "append lines: " << endl;
	afile << lineno() << " " << "this is the test file. (appended)" << endl;
	afile << lineno() << " " << "this is the test file. (appended)" << endl;
	afile << lineno() << " " << "this is the test file. (appended)" << endl;

	cout << "content after append: " << endl;
	afile.seekg(0, fstream::beg); 	// seek to beginning of file
	while(afile.good()){
		getline(afile, buffer);
		cout << buffer << endl;
	}
	afile.close();

	// delete the file
	cout << "delete the file:" << endl;
	remove(filename);

	return 0;
}
