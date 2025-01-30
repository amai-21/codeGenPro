# Makefile

#Compiler and Flags
CC = g++
CFLAGS = -g -Wall -std=c++11 

#Target executable
P0: main.o buildTree.o
	$(CC) $(CFLAGS) -o P0 main.o buildTree.o

#Object file target
main.o: main.cpp buildTree.h
	$(CC) $(CFLAGS) -c main.cpp

buildTree.o: buildTree.cpp buildTree.h
	$(CC) $(CFLAGS) -c buildTree.cpp

#clean rule:
clean:
	rm -f *.o P0

