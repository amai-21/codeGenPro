//main.cpp
#include <iostream>
#include <fstream> // For handling an input file from within the command line.
#include <string> // For using getline(), specifically for handling keyboard input from the command line.
#include <cctype> // For using isalnum() function to check if a character string is a letter or number.
#include <string> 
#include <sstream>
#include <vector> // For storing lists of strings.
#include "buildTree.h"
#include "node.h"
#include "traversals.h"

using namespace std;

int main(int argc, char* argv[]){
	//----------------------------Handling Command Line Arguments----------------------------------------------------------------------------->
	//ofstream tempFileName("temporaryFile.txt");

	//Command line argument for if file was provided - Read from the file.
	if (argc == 2) { //Resource: W3 Schools - C++ Files
			 //ifstream filename(argv[1]);
		string inputFile = argv[1];
		ifstream fileName(inputFile);

		if (fileName.peek() == EOF) {
			cout << "Error: Missing Data." << endl;
			exit(0);
		}

		string fileNameString;
		
		if (!fileName) {
			cerr << "Error: Unable to open file " << argv[1] << endl;
			return 1;
		}

		// Input validation 
		while(getline(fileName, fileNameString)){ // Character Processing Code kindly and educationally borrowed from C++ Primer textbook by Barbar E. Moo, Josee Lajoie, and Stanley B. Lippman.
			for (char c : fileNameString) {
				if (isalnum(c) || (c >= 33 && c <= 43) || isspace(c)) {
				//	tempFileName2 << fileNameString;
				} else {
					cout << "ERROR!!! Not an approved character." << endl;
					cout << "Character: " << c << endl;
					exit(0);
				}
			}	
		}
		
		// Reset the pointer from previous getline() usage so the subsequent getline() will run.
		fileName.clear();
		fileName.seekg(0);
		
		// list of strings already seen:
		vector<string> stringsSeen; 
		string readIntoVectorWords;

		//string word;
		fileName.clear();
		fileName.seekg(0);
		node_t* root = NULL; // Create an empty tree.
		string buildTreeFromFileString;
		string::size_type charCount;	
		
	       	while (getline (fileName, buildTreeFromFileString)) {
			// Build Tree
			
			istringstream lineStream(buildTreeFromFileString); // Process each line separately
			string word;

			while (lineStream >> word) {
				charCount = word.size();	 
			
		//	cout << buildTreeFromFileString;
			
				stringsSeen.push_back(word);	
				root = Insert(root, word, charCount, stringsSeen);
			}	
		}	
		

		//sstream code kindly and educationally borrowed from Geeksforgeeks.com: https://www.geeksforgeeks.org/stringstream-c-applications/
	

		// Pre Order Traversal call:
		//cout << "Preorder traversal: <---------------------------------------------->" << endl; 
		const string::size_type treeLevel = 0;
		string reNamePreOrderFile = inputFile + ".preorder";
		ofstream p0FilePreOrder(reNamePreOrderFile);
		traversePreOrder(root, treeLevel, p0FilePreOrder);
		p0FilePreOrder.close();
		
		// Post Order Traversal call:
		//cout << "Postorder traversal: <--------------------------------------------->" << endl;
		string reNamePostOrderFile = inputFile + ".postorder"; 
		ofstream p0FilePostOrder(reNamePostOrderFile);
		traversePostOrder(root, treeLevel, p0FilePostOrder);
		p0FilePostOrder.close();

		// Level Order Traversal call:
		//cout << "Level Order Traversals: <----------------------------------->" << endl;
		string reNameLevelOrderFile = inputFile + ".levelorder";
		ofstream p0FileLevelOrder(reNameLevelOrderFile);
	       	traverseLevelOrder(root, treeLevel, p0FileLevelOrder);	
		p0FileLevelOrder.close();

	} else if(argc == 1) { // Read from keyboard until simulated keyboard EOF
		// Read input into temporary file, after which the rest of the program always processes file input.
		//ofstream tempFileNameCreate("temporaryFile.txt"); 
		ofstream tempFileNameCreate("p0TemporaryFile");
		
		string keyboardReadingText;
		cout << "Enter a string. To stop, please press 'CTRL + D': ";
		while(getline(cin, keyboardReadingText)){ 
			cout << "Enter another string or press 'CTRL + D' to quit: ";
			for (char c: keyboardReadingText) {
				if (isalnum(c) || (c >= 33 && c <= 43) || isspace(c)){
				//	tempFileName << c << " ";
				}
				else{
					cout << "ERROR!! Not an approved character." << endl;
					cout << "Character: " << c << endl;
					exit(0);
				}
			}
			// read keyboard input into tempFileName.
			tempFileNameCreate << keyboardReadingText << " ";	
		}
		
		//ifstream tempFileNameRead

		cin.ignore(); // To discard any residual characters that could interere with reading into subsequent files.

		tempFileNameCreate.close();
		ifstream tempFileNameRead;
		tempFileNameRead.open("p0TemporaryFile");	

		// list of strings already seen:
		vector<string> stringsSeen;
	        string readIntoVectorWords;
		
		// Reset the pointer from previous getline() usage so the subsequent getline() calls will work.
		tempFileNameRead.clear();
		tempFileNameRead.seekg(0);	
		
	       	// Build tree.
		node_t* root = NULL;
		string buildTreeFromFileString;
		string::size_type charCount;
		while (getline(tempFileNameRead, buildTreeFromFileString)) {
			// Build tree
			istringstream lineStream(buildTreeFromFileString); // Process each line separately 
			string word;

			while (lineStream >> word) {
				charCount = word.size();
				stringsSeen.push_back(word);
				root = Insert(root, buildTreeFromFileString, charCount, stringsSeen);
		
			}
		}	
		
		tempFileNameRead.clear();
		tempFileNameRead.seekg(0);

		const string::size_type treeLevel = 0;
		// Pre Order Traversal Call:
		//cout << "Preorder traversal: <------------------------------------------>" << endl;
		string reNamePreOrderFile = "p0TemporaryFile.preorder";
		ofstream p0FilePreOrder(reNamePreOrderFile);
		traversePreOrder(root, treeLevel, p0FilePreOrder);
		p0FilePreOrder.close();

		// Post Order Traversal Call:
		//cout << "Postorder traversal: <------------------------------------------->" << endl;
		string reNamePostOrderFile = "p0TemporaryFile.postorder";
	       	ofstream p0FilePostOrder(reNamePostOrderFile);
		traversePostOrder(root, treeLevel, p0FilePostOrder);
		p0FilePostOrder.close();	

		// Level Order Traversal Call:
		//cout << "Levelorder traversal: <-------------------------------------------->" << endl;
		string reNameLevelOrderFile = "p0TemporaryFile.levelorder";
	       	ofstream p0FileLevelOrder(reNameLevelOrderFile);
		traverseLevelOrder(root, treeLevel, p0FileLevelOrder);	
		p0FileLevelOrder.close();

		tempFileNameRead.close();

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
