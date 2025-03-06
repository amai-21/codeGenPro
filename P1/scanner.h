// scanner.h
#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <string>
#include "token.h"

using namespace std;

vector<tokenStruct> tokenize(string &sourceCode); // function to take the source code as input and returns a vector of tokens.

vector<string> splitString(const string &sourceCode); // Helper function to split the source code into individual words based on space.

TokenType token(int); // function for converting large int to tokenType.

TokenType FADriver();

#endif
