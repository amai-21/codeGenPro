// token.h
#ifndef TOKEN_H
#define TOKEN_H
#include <string>

using namespace std;

enum TokenType {
	typeT1,
	typeT2,
	typeT3,
};

// Implement token as a triplet {tokenType, tokenInstance, line#}
struct tokenStruct {
	TokenType type;
	string tokenInstance;	
	int lineNumber;
};

#endif
