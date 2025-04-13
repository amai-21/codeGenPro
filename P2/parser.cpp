// parser.cpp
 
#include <iostream>
#include "parser.h"
#include "scanner.h"
#include "token.h"

using namespace std;

tokenStruct parserTokenObject; // Declare global parserTokenObject for enduring values throughout each nonterminal calls.

node_t* parser(istream &fileForScanner){

	node_t* root;
	parserTokenObject = FADriver(fileForScanner);
	//S(fileForScanner); //S starting non-terminal.

	root = S(fileForScanner);
	
	if (parserTokenObject.tokenID == EOFTk) {
		cout << "Parsing went Ok. " << endl;
	} else {
		cout << "We encountered an error. " << parserTokenObject.tokenInstance << " " << parserTokenObject.lineNumber << endl;
	}
	return root;
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


node_t* S(istream &fileForScanner){
	node_t* SNode = GetNewNode("S", 1, {});

	SNode->left = A(fileForScanner); // Processing A as first child.
	
	if (parserTokenObject.tokenInstance == "(") { // consume (
		SNode->stringsSeen.push_back(parserTokenObject.tokenInstance); // Store ( in node.
		parserTokenObject = FADriver(fileForScanner); // Process (

		node_t* bSubTree1 = B(fileForScanner); // next child.
		node_t* bSubTree2 = B(fileForScanner); // next child.

		SNode->left->right = bSubTree1; // Attach node to first B non-terminal.
		bSubTree1->right = bSubTree2; // Attach this node tothe second B non-terminal.

		if (parserTokenObject.tokenInstance == ")") {
			SNode->stringsSeen.push_back(parserTokenObject.tokenInstance); // Store ) in node.
			parserTokenObject = FADriver(fileForScanner); // Process ).
			return SNode;
		} else {
			// error:
			cerr << "Parser Error: Expected ')' but got" << parserTokenObject.tokenInstance << " on line: " << parserTokenObject.lineNumber << endl; 
			return SNode; 
		}
	} else {
		// error:
		cerr << "Parser Error: Expected '(' but got " << parserTokenObject.tokenInstance << " on line: " << parserTokenObject.lineNumber << endl; 
		return SNode; 
	}
	



}

node_t* A(istream &fileForScanner) {
	node_t* ANode = GetNewNode("A", 1, {});

	if (parserTokenObject.tokenInstance == "\"") {
		ANode->stringsSeen.push_back(parserTokenObject.tokenInstance); // Store "
		parserTokenObject = FADriver(fileForScanner);

		if (parserTokenObject.tokenID == t2Tk) {
			ANode->stringsSeen.push_back(parserTokenObject.tokenInstance);
			parserTokenObject = FADriver(fileForScanner);
			return ANode;
		} else {
			// error
			cerr << "Parser Error: Expected ')' but got " << parserTokenObject.tokenInstance << " on line: " << parserTokenObject.lineNumber << endl; 
			return ANode; 
		}	
	} else { // Predicts A -> empty.
		return NULL;
	}
}

node_t* B(istream &fileForScanner) {
	// Implement S | C | D | E | G non-terminals.
	
       // Predict S
       if (parserTokenObject.tokenInstance == "\"" || parserTokenObject.tokenInstance == "(") {
	      // BNode->stringsSeen.push_back(parserTokenObject.tokenInstance); // Store " or (
		return S(fileForScanner); // Call non-terminal S.
       }	 

 	// Predict C
       else if (parserTokenObject.tokenInstance == "#" || parserTokenObject.tokenInstance == "!") {
		return C(fileForScanner); // Call non-terminal C.
	}	

	// Predict D
       else if (parserTokenObject.tokenInstance == "$") {
		return D(fileForScanner); // Call non-terminal D.
	}	

	// Predict E
       else if (parserTokenObject.tokenInstance == "'") {
		return E(fileForScanner); // Call Non-terminal E
	}

       // Predict G
       else if (parserTokenObject.tokenID == t2Tk) {
	       	tokenStruct previousSave = parserTokenObject; // For if t2 belongs to F instead.
	       	parserTokenObject = FADriver(fileForScanner);
		
		if (parserTokenObject.tokenInstance == "%") {
			parserTokenObject = previousSave;
			return G(fileForScanner);
		} else {
			// Look ahead to see if it's F.
			parserTokenObject = previousSave;
			
			cerr << "Parser Error in B() when trying to call G. Token involved: " << parserTokenObject.tokenInstance << " on line " << parserTokenObject.lineNumber << endl;
			exit(1);
		}
       } else {
		cerr << "Error from non-terminal B. Token involved: " << parserTokenObject.tokenInstance << " on line " << parserTokenObject.lineNumber << endl;
		exit(1);
       }

		
	 
}

node_t* C(istream &fileForScanner) {
	node_t* CNode = GetNewNode("C", 1, {});

	if (parserTokenObject.tokenInstance == "#") {
		CNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
		parserTokenObject = FADriver(fileForScanner);

		if (parserTokenObject.tokenID == t2Tk) {
			CNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
			parserTokenObject = FADriver(fileForScanner);
		} else {
			// error
			cerr << "Error from non-terminal C. Token involved: " << parserTokenObject.tokenInstance << " on line " << parserTokenObject.lineNumber << endl;	 
		}
	} else if (parserTokenObject.tokenInstance == "!") {
		CNode-> stringsSeen.push_back(parserTokenObject.tokenInstance);
		parserTokenObject = FADriver(fileForScanner);

		node_t* cSubTree = F(fileForScanner);
		CNode->left = cSubTree; // Attach to node c as left child.
	} else {
		cerr << "Error from non-terminal C. Token involved: " << parserTokenObject.tokenInstance << " on line " << parserTokenObject.lineNumber << endl;
	}
	return CNode;
}

node_t* D(istream &fileForScanner) {
	node_t* DNode = GetNewNode("D", 1, {});

	if (parserTokenObject.tokenInstance == "$") {
		DNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
		parserTokenObject = FADriver(fileForScanner); // Consume $
		node_t* dSubTree = F(fileForScanner);
		DNode->left = dSubTree;
	} else {
		cerr << "Error from non-terminal D. Token involved: " << parserTokenObject.tokenInstance << " on line " << parserTokenObject.lineNumber << endl;
	}
	return DNode;
}

node_t* E(istream &fileForScanner) {
	node_t* ENode = GetNewNode("E", 1, {});

	if (parserTokenObject.tokenInstance == "'") {
		ENode->stringsSeen.push_back(parserTokenObject.tokenInstance);
		parserTokenObject = FADriver(fileForScanner); // Consume '
		
		node_t* fSubTree1 = F(fileForScanner);
		node_t* fSubTree2 = F(fileForScanner);
		node_t* fSubTree3 = F(fileForScanner);
		node_t* bSubTree = B(fileForScanner);

		ENode->left = fSubTree1;
		fSubTree1->right = fSubTree2;
		fSubTree2->right = fSubTree3;
		fSubTree3->right = bSubTree;
		
	} else {
		cerr << "Error from non-terminal E(). Token involved: " << parserTokenObject.tokenInstance << " on line " << parserTokenObject.lineNumber << endl;
	}
	return ENode;
}

node_t* F(istream &fileForScanner) {
	node_t* FNode = GetNewNode("F", 1, {});

	if (parserTokenObject.tokenID == t2Tk) {
		FNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
		parserTokenObject = FADriver(fileForScanner);

	} else if (parserTokenObject.tokenID == t3Tk) {
		FNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
		parserTokenObject = FADriver(fileForScanner);

	} else if (parserTokenObject.tokenInstance == "&") {
		FNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
		parserTokenObject = FADriver(fileForScanner);

		node_t* fSubTree1 = F(fileForScanner);
		node_t* fSubTree2 = F(fileForScanner);

		FNode->left = fSubTree1;
		fSubTree1->right =  fSubTree2;
	} else {
		cerr << "Error from non-terminal F(). Token involved: " << parserTokenObject.tokenInstance << " on line " << parserTokenObject.lineNumber << endl;
	}
	return FNode;

}

node_t* G(istream &fileForScanner) {
	node_t* GNode = GetNewNode("G", 1, {});

	if (parserTokenObject.tokenID == t2Tk) {
		GNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
		parserTokenObject = FADriver(fileForScanner);

		if (parserTokenObject.tokenInstance == "%") {
			GNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
			parserTokenObject = FADriver(fileForScanner); // Consume %
			//F(fileForScanner);
			node_t* fSubTree = F(fileForScanner);

			GNode->left = fSubTree;
		} else {
			cerr << "Error from non-terminal G. Token involved: " << parserTokenObject.tokenInstance << " on line " << parserTokenObject.lineNumber << endl;
		}
	}
	return GNode;
}


