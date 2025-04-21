// staticSemantics.h
#ifndef STATICSEMANTICS_H
#define STATICSEMANTICS_H

#include <string>
#include <unordered_set>
#include "node.h"
using namespace std;

extern unordered_set<string> symbolTable;

void insertFunction(string symbolString);
bool verify(string symbolString);
void checkStaticSemantics(node_t* rootNode); 
bool isT2Token(const string& token);
void printSymbolTable();

#endif
