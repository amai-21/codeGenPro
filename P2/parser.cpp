// testScanner.cpp
 
#include <iostream>
#include "parser.h"
#include "scanner.h"
#include "token.h"

using namespace std;

// TODO build nonterminal functions
// TODO implement the nonterminal functions in your parser function.

/*
void testScanner(istream &fileForScanner) {

	// Display the token to the screen one per line:
	tokenStruct testTokenObject;
       	do {
		testTokenObject = FADriver(fileForScanner);
	
		cout << tokenNames[testTokenObject.tokenID] << "\t" << testTokenObject.tokenInstance << "\t" << testTokenObject.lineNumber << endl;

	} while (testTokenObject.tokenID != EOFTk);	

}
*/

void parser(istream &fileForScanner){
	// Display the token to the screen one per line:
	tokenStruct testTokenObject;
	do {
		testTokenObject = FADriver(fileForScanner);

		cout << tokenNames[testTokenObject.tokenID] << "\t" << testTokenObject.tokenInstance << "\t" << testTokenObject.lineNumber << endl;
	} while (testTokenObject.tokenID != EOFTk);	


}


