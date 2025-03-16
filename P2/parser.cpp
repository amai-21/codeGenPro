// parser.cpp
#include "parser.h"
#include "token.h"
#include "scanner.h"

void parser() {
	tokenStruct parseTokenObject;


	parseTokenObject = FADriver();
	S();

	
	if (parseTokenObject.tokenID == EOFTk) {
		// continue, parse was okay.

	}
	


}

void S() {

}

void A() {

}

