// staticSemantics.cpp
#include "staticSemantics.h"
#include <unordered_set>
#include <iostream>
#include <string>
#include <cctype> // For t2 type checking.

using namespace std;

/* Unordered set code is kindly and educationally borrowed by GeeksforGeeks.org
	URL: https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/
*/
// Global Symbol Table:
unordered_set<string> symbolTable;

void insertFunction(string symbolString){
	if (symbolTable.count(symbolString) > 0) { // Check if there already is an occurrence of the string in the table.
		cerr << "ERROR! Attempted to redefine a varaible: " << symbolString << endl;
		exit(1);	
	}

	// Otherwise, insert the symbolString
	symbolTable.insert(symbolString); 
}

bool verify(string symbolString){
	if (symbolTable.count(symbolString) > 0) { // If the string is already in the container, return true.
		return true;
	}

	return false; // Otherwise, return false.
}
 
void checkStaticSemantics(node_t* rootNode) {
	if (rootNode == NULL) { // Base case
		return;
	}

	// Go through all the strings stored in this current node. FYI, rootNode = currentNode.
	for (size_t i = 0; i < rootNode->stringsSeen.size(); i++) {
		string token = rootNode->stringsSeen[i];

		// Check for variable declaration:
		if ((token == "\"" || token == "#") && i + 1 < rootNode->stringsSeen.size())  {
			// Self-note: the i+1 code snippet is to prevent out-of-bounds iteration.
			string varName = rootNode->stringsSeen[i + 1];

			if (isT2Token(varName)) {
				insertFunction(varName);
				i++; // Skip to next token since we have already processed it.
			} else {
				cerr << "Error! Invalid variable! varName in question: " << varName << endl;
				exit(1);
			}	
		} else if (isT2Token(token)) {
			if (!verify(token)) {
				cerr << "String is not in the container already. String in question: " << token << endl;
				exit(1);
			}
		}


	}

	// Recursively traverse through the tree.
	checkStaticSemantics(rootNode->left);
       	checkStaticSemantics(rootNode->right);	

}

// Helper function for checking if a token is of type 2.
bool isT2Token(const string& token) {
	if (token.size() < 2 || token[0] != '+') { // if string is less than 2 characters or first character is not +, then it is not a t2 token.
		return false;
	}
	for (size_t i = 1; i < token.size(); i++) {
		if (!isdigit(token[i])) {
			return false; // If the characters after the first character of the token is not a digit, return false.
		}
	}

	return true; // If all checks pass, it is a t2 token.
}

void printSymbolTable() {
	cout << "Symbol Table: " << endl;
	for (const auto& symbolStringVariable : symbolTable) {
		cout << symbolStringVariable << endl;
	}
}
