# Compiler and flags
CC = g++
CFLAGS = -Wall -g

#Target executable
targetExecutable: main.o binarySearchTree.o traversals.o
	$(CC) $(CFLAGS) -o targetExecutable main.o binarySearchTree.o traversals.o

#Object targets:
main.o: main.cpp binarySearchTree.h traversals.h node.h
	$(CC) $(CFLAGS) -c main.cpp

binarySearchTree.o: binarySearchTree.cpp binarySearchTree.h
	$(CC) $(CFLAGS) -c binarySearchTree.cpp

traversals.o: traversals.cpp node.h
	$(CC) $(CFLAGS) -c traversals.cpp

# Clean up object files and executable:
clean:
	rm -f *.o targetExecutable
