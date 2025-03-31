// parser.h
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
using namespace std;

// void testScanner(istream &fileForScanner);

void parser(istream &fileForScanner);

// BNF nonterminals as functions: 

void S(istream &fileForScanner);

void A(istream &fileForScanner);

void B(istream &fileForScanner);

void C(istream &fileForScanner);

void D(istream &fileForScanner);

void E(istream &fileForScanner);

void F(istream &fileForScanner);

void G(istream &fileForScanner);

#endif
