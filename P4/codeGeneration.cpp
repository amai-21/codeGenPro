// codeGeneration.cpp
#include "codeGeneration.h"
#include <iostream>

using namespace std;

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
