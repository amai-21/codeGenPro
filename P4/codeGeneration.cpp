// codeGeneration.cpp
#include "codeGeneration.h"
#include <iostream>
#include <vector>

using namespace std;

vector<string> declaredVariables; // A vector to store declared variables and later write them at the end of the assembly code file.

// function definitions
inline void fatal(const char* string) {
	cerr << "Fatal: " << string << endl;
	exit(1);
}

char* t2_2_pID (char* t2) {
	if (t2[0] != '+') {
		fatal("Expected a plus sign for the first character of a t2 token.");
	}

	t2[0] = 'p';

	return t2;
}

int t3_2_intVal(char* t3) {
	int intVal; // will hold the integer value of the t3 token.
	int caseVal; // set to +1 if upper-case (positive value) and set to -1 if lower-case (negative)

	if ((t3[0] < 65) || (t3[0] > 122)) // checking whole range from A to Z (ascii 65 - 122)
		fatal("Expected a letter for the first character of a t3 token.");

	if ((t3[0] > 90) && (t3[0] < 97)) // checking for ascii non-alphabetical characters between Z and a (ascii 91- 96)
		fatal("Expected a letter for the first character of a t3 token.");

	if ((t3[0] > 64) && (t3[0] < 91)) // upper-case letter, so integer will be positive
		caseVal = 1;

	if ((t3[0] > 96) && (t3[0] < 123)) // lower-case letter, so integer will be negative.
		caseVal = -1;

	t3[0] = '0'; // set to zero so that it will go away when converting string to integer.

	intVal = atoi(t3); // convert to integer
	intVal = intVal * caseVal; // set to negative if needed

	return intVal;


}

// Function for generating assembly code for an input program.
void codeGenerator(node_t* node, ofstream& inputFile){
		
	// S -> A ( B B )
	if (node->data == "S") {
		// run code generator for A. A is in the first node hence node->left.
		codeGenerator(node->left, inputFile); 

		// FYI node->left is A. Node->left->right is (.

		node_t* firstB = node->left->right->right;
		node_t* secondB = firstB->right;

		codeGenerator(firstB, inputFile);
		codeGenerator(secondB, inputFile);

		return;

	}	

	// B -> S | C | D | E | G
	if (node->data == "B") {
		codeGenerator(node->left, inputFile);
		return;
	}	

	// A -> " t2 | empty -----> Allocate memory for t2 or identifier and initialize it to zero (we just loaded 0).
	if (node-> data == "A" && node->stringsSeen[0] == "\"") {
		string t2 = node->stringsSeen[1]; // Initialized.
		string pID = t2_2_pID(&t2[0]); // Change + to p and attach that p back to the identifier.

		inputFile << "LOAD 0\n";
		inputFile << "STORE " << pID << endl;
		
		declaredVariables.push_back(pID); 

		return;
	} else if (node-> data == "A" && node->stringsSeen[0] == "empty") { // Do nothing if we encounter epsilon.
		return;
	}
 

	// C -> # t2 | ! F ---------------->Allocate memory for an identifier or negate for Non-terminal F
	if (node-> data == "C" && node->stringsSeen[0] == "#") { 
		string t2 = node->stringsSeen[1]; // Allocate memory for an identifier.
		
		
		string pID = t2_2_pID(&t2[0]); // Change 

		inputFile << "READ " << pID << endl;
		inputFile << "LOAD " << pID << endl;

		declaredVariables.push_back(pID);
		return;


	} else if (node->data == "C" && node->stringsSeen[0] == "!") { // Negate the argument.
		
		string temp = "temp0";

		codeGenerator(node->left, inputFile); // Evaluate F in the accumulator.

		inputFile << "MULT -1" << endl;
		inputFile << "STORE " << temp << endl;
	
		declaredVariables.push_back(temp);
		return;	
	}	

	// D -> $ F ------> Print out the value of the identifier or immediate number to the screen 
	
	if (node->data == "D" && node->stringsSeen[0] == "$") { 
	
		string temp = "temp0";

		codeGenerator(node->left, inputFile);

		inputFile << "WRITE " << temp << endl;

		declaredVariables.push_back(temp);

		return;
	}

	// E -> ' F F F B
	if (node->data == "E" && node->stringsSeen[0] == "'") {
		string firstF = "F1";
		string secondF = "F2";
		string thirdF = "F3";

		declaredVariables.push_back(firstF);
		declaredVariables.push_back(secondF);
		declaredVariables.push_back(thirdF);

		// Evaluate first F and store it.
		codeGenerator(node->left, inputFile);
	       	inputFile << "STORE " << firstF << endl;	

		// Evaluate second F and store it.
		codeGenerator(node->left->right, inputFile);
	       	inputFile << "STORE " << secondF << endl;

		// Compare F1 results and F2 results.
		inputFile << "LOAD " << firstF << endl;
		inputFile << "SUB " << secondF << endl;
		inputFile << "BRZNEG out" << endl;

		// Evaluate F3 and store it as a counter in the accumulator	
		codeGenerator(node->left->right->right, inputFile);
		inputFile << "STORE " << thirdF << endl;
	       	inputFile << "LOAD " << thirdF << endl;
		inputFile << "loop: SUB 1" << endl; 
		
		node_t* bNode = node->left->right->right->right; // Repeat argument N number of times.
		codeGenerator(bNode->left, inputFile);

		inputFile << "BRZNEG loop" << endl;
		inputFile << "out: NOOP" << endl;

		return;
			
	}	

	// F -> t2 | t3 | & F F
	if (node->data == "F") {
		// t2 production
		if (node->left->data == "t2") {
			string identifier = node->left->stringsSeen[0]; // Get t2 token as string.
			string pID = t2_2_pID(&identifier[0]); // Convert +'s to p's.
			inputFile << "LOAD " << pID << endl; // Leave value in the accumulator.
			return;

		} else if (node->left->data == "t3") { // t3 production
			string tokenInteger = node->left->stringsSeen[0]; // Retrieve t3 token as a string.
			int tokenIntegerVariable = t3_2_intVal(&tokenInteger[0]); // convert the t3 token into an integer without the first letter.

			inputFile << "LOAD " << tokenIntegerVariable << endl; // Leave value in accumulator.
			return;
		} else if (node->stringsSeen[0] == "&") { // Add the value for identifier plus the second argument.
			
			node_t* firstF = node->left;
			node_t* secondF = node->left->right;

			// Declare temporary variables.
			string temp1 = "temp1";
		       string temp2 = "temp2";

			//Generate code for first F and store result in temp1.
			codeGenerator(firstF, inputFile);
	 		
			inputFile << "STORE " << temp1 << endl;
			declaredVariables.push_back(temp1);			

			// Generate code for second F. Add first result to the accumulator and then store it to second temporary variable.
			codeGenerator(secondF, inputFile);
			inputFile << "STORE " << temp2 << endl;
			declaredVariables.push_back(temp2);

			inputFile << "LOAD " << temp1 << endl;
			inputFile << "ADD " << temp2 << endl;
			inputFile << "STORE " << temp1 << endl;	

			return;
		}	
	}

	// G -> t2 % F ------> Assign the t2 token to the results of F.
	if (node->data == "G") {
		string identifier = node->left->stringsSeen[0];
		string pID = t2_2_pID(&identifier[0]);

		string tempVariable = "temp1";

		node_t* FResult = node->left->right->right;
		// Generate code for F and set identifier to the result of F.
		codeGenerator(FResult, inputFile); 

		inputFile << "STORE " << pID << endl;


		return;
	}

}	
