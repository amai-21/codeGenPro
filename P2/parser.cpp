// parser.cpp
 
#include <iostream>
#include "parser.h"
#include "scanner.h"
#include "token.h"

using namespace std;

tokenStruct parserTokenObject; // Declare global parserTokenObject for enduring values throughout each nonterminal calls.

void parser(istream &fileForScanner){

	parserTokenObject = FADriver(fileForScanner);
	S(fileForScanner); //S starting non-terminal.

}
/*
 BNF: 

	S -> A ( B B )
	A -> " t2 | empty
	B -> S | C | D | E | G
	C -> # t2 | ! F
	D -> $ F
	E -> ' F F F B
	F -> t2 | t3 | & F F
	G -> t2 % F
*/


void S(istream &fileForScanner){
	A(fileForScanner); // Processing A.
	
	if (parserTokenObject.tokenInstance == "(") { // consume (
		parserTokenObject = FADriver(fileForScanner);
		B(fileForScanner);
		B(fileForScanner);

		if (parserTokenObject.tokenInstance == ")") {
			parserTokenObject = FADriver(fileForScanner);
		} else {
			// error:
			exit(0); 
		}
	} else {
		// error:
		exit(0); 
	}

}

void A(istream &fileForScanner) {
	if (parserTokenObject.tokenInstance == "\"") {
		parserTokenObject = FADriver(fileForScanner);
		if (parserTokenObject.tokenID == t2Tk) {
			return;
		} else {
			// error
			exit(0); 
		}	
	} else { // Predicts A -> empty.
		return;
	}
}

void B(istream &fileForScanner) {
	// Implement S | C | D | E | G non-terminals.
	
       // Predict S
       if (parserTokenObject.tokenInstance == "\"" || parserTokenObject.tokenInstance == "(") {
		S(fileForScanner); // Call non-terminal S.
       }	 

 	// Predict C
       else if (parserTokenObject.tokenInstance == "#" || parserTokenObject.tokenInstance == "!") {
		C(fileForScanner); // Call non-terminal C.
	}	

	// Predict D
       else if (parserTokenObject.tokenInstance == "$") {
		D(fileForScanner); // Call non-terminal D.
	}	

	// Predict E
       else if (parserTokenObject.tokenInstance == "'") {
		E(fileForScanner); // Call Non-terminal E
	}

       // Predict G
       else if (parserTokenObject.tokenID == t2Tk) {
	       	tokenStruct previousSave = parserTokenObject; // For if t2 belongs to F instead.
	       	parserTokenObject = FADriver(fileForScanner);
		
		if (parserTokenObject.tokenInstance == "%") {
			parserTokenObject = previousSave;
			G(fileForScanner);
		} else {
			exit(0);
		}
       } else {
		cout << "Error from non-terminal B." << endl;
		exit(0);
       }

		
	 
}

void C(istream &fileForScanner) {
	if (parserTokenObject.tokenInstance == "#") {
		parserTokenObject = FADriver(fileForScanner);
		if (parserTokenObject.tokenID == t2Tk) {
			return;
		} else {
			// error
			exit(0); 
		}
	} else if (parserTokenObject.tokenInstance == "!") {
		parserTokenObject = FADriver(fileForScanner);
		F(fileForScanner);
	} else {
		cout << "Error from non-terminal C()" << endl;
		exit(0);
	}
}

void D(istream &fileForScanner) {
	if (parserTokenObject.tokenInstance == "$") {
		parserTokenObject = FADriver(fileForScanner); // Consume $
		F(fileForScanner);
	}
}

void E(istream &fileForScanner) {

	if (parserTokenObject.tokenInstance == "'") {
		parserTokenObject = FADriver(fileForScanner); // Consume '
		F(fileForScanner);
		F(fileForScanner);
		F(fileForScanner);
		B(fileForScanner);
	} else {
		cout << "Error from non-terminal E()" << endl;
		exit(0);
	}
}

void F(istream &fileForScanner) {
	if (parserTokenObject.tokenID == t2Tk) {
		parserTokenObject = FADriver(fileForScanner);
		return;
	} else if (parserTokenObject.tokenID == t3Tk) {
		parserTokenObject = FADriver(fileForScanner);
		return;
	} else if (parserTokenObject.tokenInstance == "&") {
		parserTokenObject = FADriver(fileForScanner);
		F(fileForScanner);
		F(fileForScanner);
	} else {
		cout << "Error from non-terminal F()" << endl;
		exit(0);
	}

}

void G(istream &fileForScanner) {
	if (parserTokenObject.tokenID == t2Tk) {
		parserTokenObject = FADriver(fileForScanner);
		if (parserTokenObject.tokenInstance == "%") {
			parserTokenObject = FADriver(fileForScanner); // Consume %
			F(fileForScanner);
		} else {
			cout << "Error in G(): Expected '%' after t2." << endl;
			exit(0);
		}
	}
}


