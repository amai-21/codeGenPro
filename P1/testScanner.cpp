// testScanner.cpp
 
#include <iostream>
#include "testScanner.h"
#include "scanner.h"
#include "token.h"

using namespace std;

void testScanner(istream &fileForScanner) {

	// Display the token to the screen one per line:
	tokenStruct testTokenObject;
       	do {
		testTokenObject = FADriver(fileForScanner);

		cout << tokenNames[testTokenObject.tokenID] << "\t" << testTokenObject.tokenInstance;

	//	if (!testTokenObject.tokenInstance.empty()) {
	//		cout << "\t" << testTokenObject.tokenInstance;
	//	}
		       //	" Instance: " << testTokenObject.tokenInstance << " Line Number: " << testTokenObject.lineNumber << endl;
		       
		if (testTokenObject.tokenID != EOFTk) {
			cout << "\t" << testTokenObject.lineNumber;
		}
		
		cout << endl;
	} while (testTokenObject.tokenID != EOFTk);	

}
