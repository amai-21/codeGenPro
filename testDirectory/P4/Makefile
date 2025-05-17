# Makefile

#Compiler and Flags
CC = g++
CFLAGS = -g -Wall -std=c++11 

#Target executable
P4: main.o buildTree.o traversals.o scanner.o token.o parser.o testTree.o staticSemantics.o codeGeneration.o
	$(CC) $(CFLAGS) -o P4 main.o buildTree.o traversals.o scanner.o token.o parser.o testTree.o staticSemantics.o codeGeneration.o

#Object file target
main.o: main.cpp buildTree.h node.h traversals.h parser.h staticSemantics.h codeGeneration.h
	$(CC) $(CFLAGS) -c main.cpp

buildTree.o: buildTree.cpp buildTree.h node.h
	$(CC) $(CFLAGS) -c buildTree.cpp

traversals.o: traversals.cpp traversals.h node.h
	$(CC) $(CFLAGS) -c traversals.cpp

scanner.o: scanner.cpp scanner.h token.h
	$(CC) $(CFLAGS) -c scanner.cpp

#testScanner.o: testScanner.cpp testScanner.h token.h scanner.h
#	$(CC) $(CFLAGS) -c testScanner.cpp

token.o: token.cpp token.h
	$(CC) $(CFLAGS) -c token.cpp

parser.o: parser.cpp parser.h token.h scanner.h
	$(CC) $(CFLAGS) -c parser.cpp

testTree.o: testTree.cpp testTree.h
	$(CC) $(CFLAGS) -c testTree.cpp

staticSemantics.o: staticSemantics.cpp staticSemantics.h
	$(CC) $(CFLAGS) -c staticSemantics.cpp

codeGeneration.o: codeGeneration.cpp codeGeneration.h
	$(CC) $(CFLAGS) -c codeGeneration.cpp

#clean rule:
clean:
	rm -f *.o P4

