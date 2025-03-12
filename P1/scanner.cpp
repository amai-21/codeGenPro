// scanner.cpp
#include <string>
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
	
	if (c >= 33 && c <= 42) { // (!-))
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

	if (c == '+') { // '+'
		return 5;
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
		return EOFtk;
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

	// TODO Handle string input from scanner file.

	currentToken.tokenInstance = S;
	currentToken.lineNumber = lineNumber;	

	nextChar nextCharObject;

//	nextCharObject.actualCharacter = getchar();

	nextCharObject.actualCharacter = fileForScanner.get();

	int driverTableColumn = columnIndices(nextCharObject.actualCharacter);
//	if (driverTableColumn == -1) {
//		cout << "Error: Invalid Character: '" << nextCharObject.actualCharacter << "'" << endl;
//		exit(0);
//	}


	//tokenStruct tokenInformation;	

	while (state < 1001) {
		nextState = driverTable[state][driverTableColumn];

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
	

		//Final states	
		if (nextState == 1002) { // Need t1 type lookup.
			//tokenStruct finalInformation;
			currentToken.tokenID = finalToTokenType(nextState);
			currentToken.tokenInstance = S; 

			return currentToken;

		} else if (nextState == 1003) { // Need t2 type lookup.
			//tokenStruct finalInformation;
			currentToken.tokenID = finalToTokenType(nextState);
			currentToken.tokenInstance = S;

			cout << "Hello" << endl;

			return currentToken;

		} else if (nextState == 1004) { // Need t3 type lookup.
			//tokenStruct finalInformation;
			currentToken.tokenID = finalToTokenType(nextState);
			currentToken.tokenInstance = S;

			return currentToken;

		} else if (nextState == 1001) { // For EOF token.
			//tokenStruct finalInformation;
			currentToken.tokenID = finalToTokenType(nextState);
			currentToken.tokenInstance = S;

			return currentToken;

		}

	       	// If not final state, keep scanning.
		state = nextState;
		S += nextCharObject.actualCharacter;
		nextCharObject.actualCharacter = fileForScanner.get(); // Move to the next character.
		
	}
}

/* Lexical Analyzer (Scanner) code was kindly and educationally borrowed from Geeksforgeeks.org: https://www.geeksforgeeks.org/lexical-analyzer-in-cpp/ */

// Constructor: 
scanner::scanner(const string &sourceCode) 
	: input(sourceCode)
	, position(0)
	{  
	initTypeT1();
	}	

// Function to initialize the typet1 map.
void scanner::initTypeT1 () {
	typet1["!"] = TokenID::t1Tk;
	typet1["\""] = TokenID::t1Tk;
	typet1["#"] = TokenID::t1Tk;
	typet1["$"] = TokenID::t1Tk;
	typet1["%"] = TokenID::t1Tk;
	typet1["&"] = TokenID::t1Tk;
	typet1["'"] = TokenID::t1Tk;
	typet1["("] = TokenID::t1Tk;
	typet1[")"] = TokenID::t1Tk;
}
	
// Function to check if a character is a digit.
bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

// Function to check if a character is a letter.
bool isLetter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');	
}

// Function to check if a character is a new line:
bool isNewLine(char c) {
	return c == '\n';
}	


string scanner::getNextToken() {

	// Define a tokenStruct object:
	tokenStruct tokenObject; 
	
	tokenObject.lineNumber = 1;

	size_t start = position;

	// Check for type t2 tokens:
	if (input[position] == '+') {
		position++;
		
		// Increment line number if new line.
		if (isNewLine(input[position])) {
			tokenObject.lineNumber++;
		}

		// Check if next character is a digit:
		if (isDigit(input[position])) {
			// Keep going.	
			position++; 
		} else {
			cout << "SCANNER ERROR. String input: " << input << "Line Number: " << tokenObject.lineNumber << endl; // Include line number right after.
	       		exit(0);		       
		}
 	
		if (isNewLine(input[position])) {
			tokenObject.lineNumber++;
		}

		while (position < input.length()) {
			position++;

			if (isNewLine(input[position])) {
				tokenObject.lineNumber++;		
			}

			if (!isDigit(input[position])) {
				cout << "SCANNER ERROR. String input: " << input << "Line Number: " << tokenObject.lineNumber << endl;
				exit(0);
			}
		}		

		return input.substr(start, position - start);


	} else if (isLetter(input[position])) { // Check for type t3 tokens:
		position++;
		// Check if next character is a digit.
		if (isDigit(input[position])) {
			// Keep going.
			position++; 
		} else {
			cout << "SCANNER ERROR. String input: " << input << "Line Number: " << tokenObject.lineNumber << endl;
			exit(0);
		}

		while (position < input.length()) {
			position++;
			if (!isDigit(input[position])) {
				cout << "SCANNER ERROR. String input: " << input << "Line Number: " << tokenObject.lineNumber << endl;
				exit(0);	
			}
		}

		return input.substr(start, position - start);	
	} else {
		cout << "SCANNER ERROR. String input: " << input << "Line Number: " << tokenObject.lineNumber << endl;
		exit(0); 
	}
}	

