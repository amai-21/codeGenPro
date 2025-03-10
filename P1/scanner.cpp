// scanner.cpp
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "scanner.h"

using namespace std;

// Driver table:
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


TokenType FADriver() { // assume nextChar set, and used as column index
	int state = 0; // inital state
	int nextState;
	string S= "";

	while (state < 1000) { // Run until reached final state.
		nextState = driverTable[state][nextChar];
		if (nextState == -2 || nextState == -3 || nextState == -1) {
			cout << "Encountered error state." << endl;
			exit(0); // report and exit.
		}
		if (nextState >= 1001) {
			if (token(nextState) == ID) { // need reserved keyword lookup
				if (S in Keywords) {
					return (KWtk, S);
				} else {
					return (IDtk, S);
				}
			} else {
				return (token(nextState), S);
			}
		} else {
			// not final
			state:=nextState;
     			append(S, nextChar);
		       	nextChar=getchar();	
		}
	}

}

/* Lexical Analyzer (Scanner) code was kindly and educationally borrowed from Geeksforgeeks.org: https://www.geeksforgeeks.org/lexical-analyzer-in-cpp/ */

// Constructor: 
LexicalAnalyzer::LexicalAnalyzer(const string &sourceCode) 
	: input(sourceCode)
	, position(0)
	{  
	initTypeT1();
	}	

// Function to initialize the typet1 map.
void LexicalAnalyzer::initTypeT1 () {
	typet1["!"] = TokenType::TYPET1;
	typet1["\""] = TokenType::TYPET1;
	typet1["#"] = TokenType::TYPET1;
	typet1["$"] = TokenType::TYPET1;
	typet1["%"] = TokenType::TYPET1;
	typet1["&"] = TokenType::TYPET1;
	typet1["'"] = TokenType::TYPET1;
	typet1["("] = TokenType::TYPET1;
	typet1[")"] = TokenType::TYPET1;
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


string LexicalAnalyzer::getNextToken() {

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

	// return input.substr(start, position - start);
}	

