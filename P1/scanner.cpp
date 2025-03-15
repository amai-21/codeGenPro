// scanner.cpp
#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include "scanner.h"

using namespace std;

// Driver Table:
const int numberOfStates = 6;
const int numberOfColumns = 6;

int driverTable[numberOfStates][numberOfColumns] {
	{0, 5, 1, -1, 1004, 3},
	{-2, -2, -2, 2, -2, -2},
	{1003, 1003, 1003, 2, 1003, 1003},
	{-3, -3, -3, 4, -3, -3},
	{1002, 1002, 1002, 4, 1002, 1002},
	{1001, 1001, 1001, 1001, 1001, 1001}
};

// Global variable nextChar is set to next character in input.
//char nextChar;

struct nextChar {
	char actualCharacter;
	int  labelColumnNumber;
};

/* Function for handling indices that map to a specific label:

	ws = 0
	(!-)) = 1
	letter = 2
	digit = 3
	EOF = 4
	+ = 5

 */

int columnIndices(char c) {

	if (isspace(c)) { // ws
		return 0;
	}

//	if (c == ' ' || c == '\t' ) {
//		return 0;
//	}

	if (c == '+') {
		return 5;
	}	

	if (c >= 33 && c <= 42 && c != '+') { // (!-))
		return 1;
	}

	if (isalpha(c)) { // letter.
		return 2;
	}

	if (isdigit(c)) { // digit.
		return 3;
	}

	if (c == EOF) { // EOF
		return 4;
	}

//	if (c == '+') { // '+'
//		return 5;
//	}

	return -1; // Error case for unknown characters.
}


// Function for converting large int to tokenType.
TokenID finalToTokenType(int finalState) {
	if (finalState == 1001) {
		return t1Tk;
	} else if (finalState == 1002) {
		return t2Tk;
	} else if (finalState == 1003) {
		return t3Tk;
	} else if (finalState == 1004) {
		return EOFTk;
	} else {
		cout << "Error: Unknown final state " << finalState << endl;
		exit(0);
	}


//	return -1;
}	

tokenStruct FADriver(istream &fileForScanner) {
	int state = 0; // initial state
	int nextState;
	string S = "";
	static int lineNumber = 1;

	

	tokenStruct currentToken;
	currentToken.tokenInstance = S;
	currentToken.lineNumber = lineNumber;	

	nextChar nextCharObject;
	nextCharObject.actualCharacter = fileForScanner.get();
	nextCharObject.labelColumnNumber = columnIndices(nextCharObject.actualCharacter);

	while (state < 1001) {
		nextState = driverTable[state][nextCharObject.labelColumnNumber];

		int tokenLineNumber = lineNumber;

		//cout << "DEBUG: " << S << " at Line: " << tokenLineNumber << " State: " << state << endl;

		// Handle line Numbers:
		if (nextCharObject.actualCharacter == '\n') {
			lineNumber++;
		}	

		// Handling error states:
		if (nextState == -1 || nextState == -2 || nextState == -3) {
		//	cout << "Encountered error state" << endl;
			cout << "SCANNER ERROR: Line:" << lineNumber << " " << S << endl;
			exit(0);
		}
	
		if (nextState >= 1001) {
			currentToken.tokenID = finalToTokenType(nextState);
			currentToken.lineNumber = tokenLineNumber;

			currentToken.tokenInstance = S;
			return currentToken;
		}

		state = nextState;
		S += nextCharObject.actualCharacter;
		nextCharObject.actualCharacter = fileForScanner.get(); // Move to the next character.

		nextCharObject.labelColumnNumber = columnIndices(nextCharObject.actualCharacter);
	}

	return currentToken;
}

