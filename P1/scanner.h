// scanner.h
#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <string>
#include "token.h"
#include <unordered_map>

using namespace std;

TokenID finalToTokenType (int finalState); // function for converting large int to TokenType

tokenStruct FADriver(istream &fileForScanner);

// column indices that correspond with the DFSA table's specified labels:
int columnIndices(char c); 

class scanner {
	private: 
		string input;
		size_t position;
		unordered_map<string, TokenID> typet1;
		void initTypeT1();

	public:
		scanner(const string &sourceCode);
		string getNextToken();

};

#endif
