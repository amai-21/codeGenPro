// scanner.h
#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include "token.h"


using namespace std;

TokenID finalToTokenType (int finalState); // function for converting large int to TokenType

tokenStruct FADriver(istream &fileForScanner);

// column indices that correspond with the DFSA table's specified labels:
int columnIndices(char c); 
#endif
