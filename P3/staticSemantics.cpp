// staticSemantics.cpp
#include "staticSemantics.h"
#include <unordered_set>
#include <iostream>
using namespace std ;

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

}
 
void checkStaticSemantics(node_t* treeRoot) {

}
