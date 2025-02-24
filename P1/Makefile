# Makefile

#Compiler and Flags
CC = g++
CFLAGS = -g -Wall -std=c++11 

#Target executable
P1: main.o buildTree.o traversals.o
	$(CC) $(CFLAGS) -o P1 main.o buildTree.o traversals.o

#Object file target
main.o: main.cpp buildTree.h node.h traversals.h
	$(CC) $(CFLAGS) -c main.cpp

buildTree.o: buildTree.cpp buildTree.h node.h
	$(CC) $(CFLAGS) -c buildTree.cpp

traversals.o: traversals.cpp traversals.h node.h
	$(CC) $(CFLAGS) -c traversals.cpp
#clean rule:
clean:
	rm -f *.o P1

