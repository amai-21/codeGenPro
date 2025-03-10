// scanner.cpp
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "scanner.h"

using namespace std;

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

