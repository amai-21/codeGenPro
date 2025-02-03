//main.cpp
#include <iostream>
#include <fstream> // For handling an input file from within the command line.
#include <string> // For using getline(), specifically for handling keyboard input from the command line.
#include <cctype> // For using isalnum() function to check if a character string is a letter or number.
#include "buildTree.h"

using namespace std;

int main(int argc, char* argv[]){

	//----------------------------Handling Command Line Arguments----------------------------------------------------------------------------->
	
	//Declare a file object for reading:
	ifstream fileName;

	//Command line argument for if file was provided - Read from the file.
	if (argc == 2) { //Resource: W3 Schools - C++ Files
		//ifstream filename(argv[1]);
		fileName.open(argv[1]);
		//Test for handling a filename argument
		//string testString;
		//while (getline (fileName, testString)) {
		//	cout << testString;
		//}

		//TODO traverse through the file. If there is a non-approved character, abort the program and display an appropriate error message.
		string fileNameString; 
		while(getline(fileName, fileNameString)) {
			if (!isalnum(fileNameString) || fileNameString < 33 || fileNameString > 43) {
				cout << "Detected a character that wasn't valid." << endl;
				cout << "Character: " << fileNameString << endl;
				cout << "Program will now abort." << endl;
				exit(0);
			}
		}
		
	} else if(argc == 1) { // Read from keyboard until simulated keyboard EOF
		ofstream tempFilename("keyboardInputFile.txt");
		string keyboardReadingText;
		
		
		cout << "Enter a string. To stop, please press 'CTRL + D': ";
		while(getline(cin, keyboardReadingText)){ 
			cout << "Enter another string or press 'CTRL + D' to quit: ";
			//TODO Check if the keyboard input is an approved character string. If it isn't, then abort the program and display an appropriate error message.

			tempFilename << keyboardReadingText;
			tempFilename << " "; // To delimit words by one space.	
		}
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

	fileName.close();
	//-----------------------------------------------------Input Data Validation---------------------------------------------------------------->
	

	return 0;
}
