// testScanner.cpp
 
#include <iostream>
#include <algorithm>
#include "testScanner.h"
#include "scanner.h"
#include "token.h"

using namespace std;

void testScanner(istream &fileForScanner) {

	// Display the token to the screen one per line:
	tokenStruct testTokenObject;
       	do {
		testTokenObject = FADriver(fileForScanner);
	
		cout << tokenNames[testTokenObject.tokenID] << "\t" << testTokenObject.tokenInstance << "\t" << testTokenObject.lineNumber << endl;

	} while (testTokenObject.tokenID != EOFTk);	

}
