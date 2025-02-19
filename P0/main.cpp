//main.cpp
#include <iostream>
#include <fstream> // For handling an input file from within the command line.
#include <string> // For using getline(), specifically for handling keyboard input from the command line.
#include <cctype> // For using isalnum() function to check if a character string is a letter or number.
#include <string> 
#include <vector> // For storing lists of strings.
#include "buildTree.h"
#include "node.h"
#include "traversals.h"

using namespace std;

int main(int argc, char* argv[]){
	//----------------------------Handling Command Line Arguments----------------------------------------------------------------------------->
	ofstream tempFileName("temporaryFile.txt");

	//Command line argument for if file was provided - Read from the file.
	if (argc == 2) { //Resource: W3 Schools - C++ Files
			 //ifstream filename(argv[1]);
		ifstream fileName(argv[1]);
		string fileNameString;
		
		if (!fileName) {
			cerr << "Error: Unable to open file " << argv[1] << endl;
			return 1;
		}

		// Input validation 
		while(getline(fileName, fileNameString)){
			for (char c : fileNameString) {
				if (isalnum(c) || (c >= 33 && c <= 43) || isspace(c)) {
				//	tempFileName2 << fileNameString;
				} else {
					cout << "Not an approved character." << endl;
					cout << "Character: " << c << endl;
					exit(0);
				}
			}
//			tempFileName << fileNameString << " ";
			
		}

		// Reset the pointer from previous getline() usage so the subsequent getline() will run.
		fileName.clear();
		fileName.seekg(0);
		
		// list of strings already seen:
		vector<string> stringsSeen; 
		string readIntoVectorWords;
		while (fileName >> readIntoVectorWords) {
			stringsSeen.push_back(readIntoVectorWords);
		}	
		
		fileName.clear();
		fileName.seekg(0);
		node_t* root = NULL; // Create an empty tree.
		string buildTreeFromFileString;
		string::size_type charCount;	
		string::size_type i = 0;
	       	while (getline (fileName, buildTreeFromFileString)) {
			// Build Tree
		//	charCount = buildTreeFromFileString.size();
			charCount = stringsSeen[i].size();	
			root = Insert(root, buildTreeFromFileString, charCount, stringsSeen);
			i++;
		}	
		
		// Preorder traversal call.
		const string::size_type treeLevel = 0;

		ofstream p0FilePreOrder("p0File.preorder");
		traversePreOrder(root, treeLevel, p0FilePreOrder);
		p0FilePreOrder.close();

		// Level Order Traversal call.
		cout << "Level Order Traversals: <----------------------------------->" << endl;
		ofstream p0FileLevelOrder("p0File.levelorder");
	       	traverseLevelOrder(root, treeLevel, p0FileLevelOrder);	
		p0FileLevelOrder.close();

		tempFileName.close();

//		root = Insert(root, tempFileName);
//		tempFileName.close();
	} else if(argc == 1) { // Read from keyboard until simulated keyboard EOF
		string keyboardReadingText;

		cout << "Enter a string. To stop, please press 'CTRL + D': ";
		while(getline(cin, keyboardReadingText)){ 
			cout << "Enter another string or press 'CTRL + D' to quit: ";
			for (char c: keyboardReadingText) {
				if (isalnum(c) || (c >= 33 && c <= 43) || isspace(c)){
				//	tempFileName << c << " ";
				}
				else{
					cout << "Not an approved character." << endl;
					cout << "Character: " << c << endl;
					exit(0);
				}
			}
			tempFileName << keyboardReadingText << " ";
		}

		tempFileName.close();

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
