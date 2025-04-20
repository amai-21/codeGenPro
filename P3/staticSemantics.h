// staticSemantics.h
#ifndef STATICSEMANTICS_H
#define STATICSEMANTICS_H

#include <string>
#include "node.h"
using namespace std;

void insertFunction(string symbolString);
bool verify(string symbolString);
void checkStaticSemantics(node_t* treeRoot); 

#endif
