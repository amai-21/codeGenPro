# Makefile

#Compiler and Flags
CC = g++
CFLAGS = -g -Wall -std=c++11 

#Target executable
P0: prog.o buildTree.o
	$(CC) $(CFLAGS) -o targetExecutable prog.o

#Object file target
prog.o: prog.cpp
	$(CC) $(CFLAGS) -c prog.cpp

buildTree.o: buildTree.cpp buildTree.h
	$(CC) $(CFLAGS) -c buildTree.cpp

#clean rule:
clean:
	rm -f *.o targetExecutable

