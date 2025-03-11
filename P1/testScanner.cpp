// testScanner.cpp
 
#include <iostream>
#include "testScanner.h"
#include "scanner.h"
#include "token.h"

using namespace std;

void testScanner() {

	// Display the token to the screen one per line:
	tokenStruct testTokenObject;
       	do {
		testTokenObject = FADriver();

		cout << "Token: " << tokenNames[testTokenObject.tokenID] << " Instance: " << testTokenObject.tokenInstance << " Line Number: " << testTokenObject.lineNumber << endl;
	} while (testTokenObject.tokenID != EOFtk);	

}
