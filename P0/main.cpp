//main.cpp
#include <iostream>
#include <fstream> // For handling an input file from within the command line.
#include <string> // For using getline(), specifically for handling keyboard input from the command line.
#include "buildTree.h"

using namespace std;

int main(int argc, char* argv[]){
	//Command line argument for if file was provided - Read from the file.
	if (argc > 1) { //Resource: W3 Schools - C++ Files
		ifstream filename(argv[1]);

		//Test for handling a filename argument
		//string testString;
		//while (getline (filename, testString)) {
		//	cout << testString;
		//}
		filename.close();
	} else if(argc == 1) { // Read from keyboard until simulated keyboard EOF
		ofstream tempFilename("keyboardInputFile.txt");
		string keyboardReadingText;
		
		
		cout << "Enter a string. To stop, please press 'CTRL + D': ";
		while(getline(cin, keyboardReadingText)){ 
			cout << "Enter another string or press 'CTRL + D' to quit: ";

			tempFilename << keyboardReadingText;
			tempFilename << " "; // To delimit words by one space.	
		}
		//TODO: Read from tempFilename. If there are more than three strings, display an error message and quit.
	} else if(argc > 2) { // If user input 3 or more strings, display an error:
		cout << "P0 ";
		for (int i = 0; i < argc - 1; i++) {
			cout << "file" << (i + 1) << " ";
		}
		cout << endl;
		cout << "Fatal: Improper usage" <<endl;
		cout << "Usage: P0 [filename]" << endl;
		exit(0);
	}

	return 0;
}
