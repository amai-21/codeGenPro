// scanner.cpp
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "scanner.h"

using namespace std;

class LexicalAnalyzer {
private: 
	string input;
	size_t position;
	unordered_map<string, TokenType> typet1;

	// Function to initialize the typet1 map.
	void initTypeT1 () {
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

	string getNextToken() {

		size_t start = position;
		// Check for type t2 tokens:
		if (input[position] == '+') {
			position++;
			
			// Check if next character is a digit:
			if (isDigit(input[position])) {
				// Keep going.	
				position++; 
			} else {
				cout << "Invalid Token Type! This character does not belong to type T2 tokens: " << input[position] << endl;
			        cout << "Program ending..." << endl;
		       		exit(0);		       
			}

			while (position < input.length() && isDigit(input[position])) {
				position++;
			}		
			return input.substr(start, position - start);	
		}	
	}	

public:
	

};

/* Code kindly and educationally borrowed from "Writing a Lexer in C++: A Step-by-Step Guide" by Tharun Appu. https://medium.com/@tharunappu2004/writing-a-lexer-in-c-a-step-by-step-guide-a1d5c55ac04d */
/*
// Function tokenize to take source code as input and returns a vector of tokens.
vector<tokenStruct> tokenize(string & sourceCode) {
	vector<tokenStruct> tokens;

	vector<string> src = splitString(sourceCode);

	while (!src.empty()) {
		if (src.front() == "!") {
			tokens.push_back(tokens(shift(src), TokenType::typeT1));
		}
	}

	return tokens; 
}

// Split the source code into individual word based on space using a range based for loop that runs through each individual characters and then pushes the word into a vector.
vector<string> splitString(const string &sourceCode){
	vector<string> words;
	string word;

	for (char ch : sourceCode) {
		if (ch != ' ') {
			word += ch;
		} else if (!word.empty()) {
			words.push_back(word);
			word.clear();
		}
	}

	if (!word.empty()) {
		words.push_back(word);
	}

	return words;
}

*/
