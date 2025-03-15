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

/* Function for handling indices that map to a specific label:

	ws = 0
	(!-)) = 1
	letter = 2
	digit = 3
	EOF = 4
	+ = 5

 */

// Function that matches a character with a specific column label according to the driver table above.
int columnIndices(char c) {

	if (isspace(c)) { // ws
		return 0;
	}

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

// Lookahead designed as a struct.
struct nextChar {
	char actualCharacter;
	int labelColumnNumber;
};

// Driver function that takes in a file and then starts scanning the associated strings and see if it's a valid token.
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

		// Handle line Numbers:
		if (nextCharObject.actualCharacter == '\n') {
			lineNumber++;
		}

		// Handling error states: 
		if (nextState == -1 || nextState == -2 || nextState == -3) {
			cout << "SCANNER ERROR: Line:" << lineNumber << " Character: " << nextCharObject.actualCharacter << endl;
			exit(0);
		}
	
		if (nextState >= 1001) { // Return the token once we've reached a final state.
			currentToken.tokenID = finalToTokenType(nextState);
			currentToken.lineNumber = tokenLineNumber;

			currentToken.tokenInstance = S;

			if (!isspace(nextCharObject.actualCharacter)) { // For if a line of string is merged. Put that character back in so that it gets read ONLY if it isn't a whitespace.
				fileForScanner.unget();
			}

			return currentToken;
		}


		state = nextState;
		S += nextCharObject.actualCharacter;
		nextCharObject.actualCharacter = fileForScanner.get(); // Move to the next character.
		nextCharObject.labelColumnNumber = columnIndices(nextCharObject.actualCharacter);
	}

	return currentToken;
}

