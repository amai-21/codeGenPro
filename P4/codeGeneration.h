// codeGeneration.h
#ifndef CODEGENERATION_H
#define CODEGENERATION_H

#include "node.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

extern vector<string> declaredVariables;

inline void fatal(const char* string);

// prototypes:
char* t2_2_pID(char* t2);
int t3_2_intVal(char* t2ID);


void codeGenerator(node_t* root, ofstream& inputFile);

void declareVariable(string var);

#endif
