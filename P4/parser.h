// parser.h
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "node.h"
#include "buildTree.h"

using namespace std;

// void testScanner(istream &fileForScanner);

node_t* parser(istream &fileForScanner);

// BNF nonterminals as functions: 

node_t* S(istream &fileForScanner);

node_t* A(istream &fileForScanner);

node_t* B(istream &fileForScanner);

node_t* C(istream &fileForScanner);

node_t* D(istream &fileForScanner);

node_t* E(istream &fileForScanner);

node_t* F(istream &fileForScanner);

node_t* G(istream &fileForScanner);

#endif
