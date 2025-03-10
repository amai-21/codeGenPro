// scanner.h
#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <string>
#include "token.h"

using namespace std;

TokenID token (int); // function for converting large int to TokenType

tokenStruct FADriver();

class LexicalAnalyzer {
	private: 
		string input;
		size_t position;
		unordered_map<string, TokenID> typet1;
		void initTypeT1();

	public:
		LexicalAnalyzer(const string &sourceCode);
		string getNextToken();

};

#endif
