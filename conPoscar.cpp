// reading a text file
#include <iostream>
#include <fstream>
#include <string>

#define num_skip_lines 6

using namespace std;

int main (int argc, char *argv[]) {
	if (argc!=2) {
		cout << "wrong number of files. First *.con than *.poscar."
	} else {
		string line;
		ifstream infile (argv[0]); // load input *.con file
		ofstream outfile (argv[1]);

		if (myfile.is_open()) {
			while ( getline (myfile,line) ) {
				cout << line << '\n';
			}
			myfile.close();
		} else 
			cout << "Unable to open file";

	}

	return 0;
}