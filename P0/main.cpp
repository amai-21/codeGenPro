//main.cpp
#include <iostream>
#include <fstream> // For handling an input file from within the command line.
#include <string> // For using getline(), specifically for handling keyboard input from the command line.
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
	} else if(argc == 1) { // Read from keyboard until simulated keyboard EOF
		ofstream tempFilename("tempFile.txt");
		string keyboardReadingText;

		while(getline() != EOF){
			getline(cin, keyboardReadingText);
		}
	}

	return 0;
}
