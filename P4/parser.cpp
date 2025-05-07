// parser.cpp
 
#include <iostream>
#include <fstream>
#include "parser.h"
#include "scanner.h"
#include "token.h"

using namespace std;

tokenStruct parserTokenObject; // Declare global parserTokenObject for enduring values throughout each nonterminal calls.

node_t* parser(istream &fileForScanner, ofstream &secondFile){

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

	node_t* ANode = A(fileForScanner);
	SNode->left = ANode;

	if (parserTokenObject.tokenInstance == "(") { // consume (
		// Process (
		node_t* leftParenNode = GetNewNode("T1Tk", 1, {parserTokenObject.tokenInstance});
		ANode->right = leftParenNode; 
		parserTokenObject = FADriver(fileForScanner);

		

		node_t* bSubTree1 = B(fileForScanner); // next child.

		leftParenNode->right = bSubTree1;

		node_t* bSubTree2 = B(fileForScanner); // next child.
		bSubTree1->right = bSubTree2;

		if (parserTokenObject.tokenInstance == ")") {
			node_t* rightParenNode = GetNewNode("T1Tk", 1, {parserTokenObject.tokenInstance});
			bSubTree2->right = rightParenNode;
			parserTokenObject = FADriver(fileForScanner);
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
	
	return SNode;
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
		ANode->stringsSeen.push_back("empty");
		return ANode;
	}
}

node_t* B(istream &fileForScanner) {
	// Implement S | C | D | E | G non-terminals.
	
	node_t* BNode = GetNewNode("B", 1, {});

       // Predict S
       if (parserTokenObject.tokenInstance == "\"" || parserTokenObject.tokenInstance == "(") {
		node_t* sSubTree = S(fileForScanner);
		BNode->left = sSubTree;
		return BNode;
       }	 

 	// Predict C
       else if (parserTokenObject.tokenInstance == "#" || parserTokenObject.tokenInstance == "!") {
		node_t* cSubTree = C(fileForScanner);
		BNode->left = cSubTree;
		return BNode;
		//return C(fileForScanner); // Call non-terminal C.
	}	

	// Predict D
       else if (parserTokenObject.tokenInstance == "$") {
	       	node_t* dSubTree = D(fileForScanner);
		BNode->left = dSubTree;
		return BNode;
		//return D(fileForScanner); // Call non-terminal D.
	}	

	// Predict E
       else if (parserTokenObject.tokenInstance == "'") {
	       	node_t* eSubTree = E(fileForScanner);
		BNode->left = eSubTree;
		return BNode;
		//return E(fileForScanner); // Call Non-terminal E
	}
       // Predict G
       else if (parserTokenObject.tokenID == t2Tk) {
	       	node_t* gSubTree = G(fileForScanner);
		BNode->left = gSubTree;
		return BNode;
	      	
       } else {
		cerr << "Error from non-terminal B. Token involved: " << parserTokenObject.tokenInstance << " on line " << parserTokenObject.lineNumber << endl;
		return BNode;
       }
	
       return BNode;
		
	 
}

node_t* C(istream &fileForScanner) {
	node_t* CNode = GetNewNode("C", 1, {});

	if (parserTokenObject.tokenInstance == "#") {
		CNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
		node_t* poundNode = GetNewNode("t1", 1, {parserTokenObject.tokenInstance});
		CNode->left = poundNode;
		parserTokenObject = FADriver(fileForScanner);

		if (parserTokenObject.tokenID == t2Tk) {
			CNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
			node_t* t2Node = GetNewNode("t2", 1, {parserTokenObject.tokenInstance});
			CNode->right = t2Node;
			parserTokenObject = FADriver(fileForScanner);
			return CNode;
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
		node_t* dollarNode = GetNewNode("t1", 1, {parserTokenObject.tokenInstance});
		DNode->left = dollarNode;
		parserTokenObject = FADriver(fileForScanner); // Consume $
		node_t* dSubTree = F(fileForScanner);
		DNode->right = dSubTree;
		
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
//	cout << "In F(), tokenID = " << parserTokenObject.tokenID << " tokenInstance =  " < parserTokenObject.tokenInstance << " line = " << parserTokenObject.lineNumber << endl;
	node_t* FNode = GetNewNode("F", 1, {});

	if (parserTokenObject.tokenID == t2Tk) {
		FNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
		node_t* t2Node = GetNewNode("t2", 1, {parserTokenObject.tokenInstance});
		FNode->left = t2Node;
		parserTokenObject = FADriver(fileForScanner);
		return FNode;

	} else if (parserTokenObject.tokenID == t3Tk) {
		FNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
		node_t* t3Node = GetNewNode("t3", 1, {parserTokenObject.tokenInstance});
		FNode->left = t3Node;
		parserTokenObject = FADriver(fileForScanner);
		return FNode;

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
		node_t* t2Node = GetNewNode("t2", 1, {parserTokenObject.tokenInstance});
		GNode->left = t2Node;
		parserTokenObject = FADriver(fileForScanner);

		if (parserTokenObject.tokenInstance == "%") {

			GNode->stringsSeen.push_back(parserTokenObject.tokenInstance);
			node_t* percentNode = GetNewNode("t1", 1, {parserTokenObject.tokenInstance});
			t2Node->right = percentNode;
			parserTokenObject = FADriver(fileForScanner); // Consume %
			//parserTokenObject = FADriver(fileForScanner);

			node_t* fSubTree = F(fileForScanner);
			percentNode->right = fSubTree;
			return GNode;
		} else {
			cerr << "Error from non-terminal G. Token involved: " << parserTokenObject.tokenInstance << " on line " << parserTokenObject.lineNumber << endl;
	
			return GNode;	
		}

	} else {
		cerr << "Error from non-terminal G. Token involved: " << parserTokenObject.tokenInstance << " on line " << parserTokenObject.lineNumber << endl;
		return GNode;
	}
	return GNode;
}


