// staticSemantics.h
#ifndef STATICSEMANTICS_H
#define STATICSEMANTICS_H

#include <string>
#include <vector>
#include "node.h"
using namespace std;

extern vector<string> symbolTable;

void insertFunction(string symbolString);
bool verify(string symbolString);
void checkStaticSemantics(node_t* rootNode); 
bool isT2Token(const string& token);
void printSymbolTable();

#endif
