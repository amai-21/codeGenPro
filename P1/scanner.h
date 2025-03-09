// scanner.h
#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <string>
#include "token.h"

using namespace std;

class LexicalAnalyzer {
	private: 
		string input;
		size_t position;
		unordered_map<string, TokenType> typet1;
		void initTypeT1();

	public:
		LexicalAnalyzer(const string &sourceCode);
		string getNextToken();

};
#endif
