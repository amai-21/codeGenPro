// token.h

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

enum TokenType {
	typeT1, // Characters: ! " # $ % & ' ( ) These characters correspond to ascii numbers 33 to 41.
	typeT2, // Begin with a single + followed by one or more digits (0-9).
	typeT3, // Begin with a single letter, (a-z, A-Z), followed by one or more digits (0-9).
};

// Implement token as a triplet {tokenType, tokenInstance, line#}
struct tokenStruct {
	TokenType type;
	string tokenInstance;	
	int lineNumber;
};

#endif
