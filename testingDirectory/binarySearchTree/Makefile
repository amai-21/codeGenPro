# compiler and flags
CC = g++
CFLAGS = -Wall -g

# Targets and dependencies
targetExecutable: main.o IntBinaryTree.o
	$(CC) $(CFLAGS) -o targetExecutable main.o IntBinaryTree.o


#Object Target files:
main.o: main.cpp IntBinaryTree.h
	$(CC) $(CFLAGS) -c main.cpp

IntBinaryTree.o: IntBinaryTree.cpp IntBinaryTree.h
	$(CC) $(CFLAGS) -c IntBinaryTree.cpp

#Clean up object files and target executable:
clean:
	rm -f *.o targetExecutable
