// scanner.cpp
#include <string>
#include <vector>
#include "scanner.h"

using namespace std;

/* Code kindly and educationally borrowed from "Writing a Lexer in C++: A Step-by-Step Guide" by Tharun Appu. https://medium.com/@tharunappu2004/writing-a-lexer-in-c-a-step-by-step-guide-a1d5c55ac04d */

// Function tokenize to take source code as input and returns a vector of tokens.
vector<tokenStruct> tokenize(string & sourceCode) {
	vector<tokenStruct> tokens;

	vector<string> src = splitString(sourceCode);

	while (!src.empty()) {
		if (src.front() == "(") {
			// Tokenization logic goes here.
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
