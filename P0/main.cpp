//main.cpp
#include <iostream>
#include <fstream> // For handling an input file from within the command line.
#include <string> // For using getline(), specifically for handling keyboard input from the command line.
#include <cctype> // For using isalnum() function to check if a character string is a letter or number.
#include <string> 
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
		string fileNameString;

		//TODO Input data validation
		while(getline(fileName, fileNameString)){
			for (char c : fileNameString) {
				if (isalnum(c) || (c >= 33 && c <= 43) || isspace(c)) {
					// Do nothing.
				} else {
					cout << "Not an approved character." << endl;
					cout << "Character: " << c << endl;
					exit(0);
				}
			}
		}

	} else if(argc == 1) { // Read from keyboard until simulated keyboard EOF
		ofstream tempFilename("keyboardInputFile.txt");
		string keyboardReadingText;


		cout << "Enter a string. To stop, please press 'CTRL + D': ";
		while(getline(cin, keyboardReadingText)){ 
			cout << "Enter another string or press 'CTRL + D' to quit: ";

			for (char c: keyboardReadingText) {
				if (isalnum(c) || (c >= 33 && c <= 43) || isspace(c)){
					//Do nothing.
				}
				else{
					cout << "Not an approved character." << endl;
					cout << "Character: " << c << endl;
					exit(0);
				}
			}
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
