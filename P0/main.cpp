//main.cpp
#include <iostream>
#include <fstream> // For handling an input file from within the command line.
#include "buildTree.h"

using namespace std;

int main(int argc, char* argv[]){
	
	//Command line argument for if file was provided
	if (argc > 1) { //Resource: W3 Schools - C++ Files
		ifstream filename(argv[1]);

		//Test for handling a filename argument
		//string testString;
		//while (getline (filename, testString)) {
		//	cout << testString;
		//}
		filename.close();
	} else if(argv == 1) { // Read from keyboard until simulated keyboard EOF
		ofstream tempFilename("tempFile.txt");		
	}

	return 0;
}
