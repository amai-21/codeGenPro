// testTree.cpp
#include <iostream>
#include "testTree.h"
#include "node.h"
#include "parser.h"

void testTreePrint(node_t* rootNode, string::size_type treeLevel){
	if (rootNode == NULL) return; // Base case for this recursive function call.

	// Implement the indentation level as a string. I.e., if indentationLevel = 4, indentation will have four empty spaces as a string.
	string::size_type indentationLevel = treeLevel * 4;
	string indentation(indentationLevel, ' ');

	cout << indentation << rootNode->data << endl; // Print the node's non-terminal/terminal name.


	for (const string& nodeContents : rootNode->stringsSeen) {
		cout << indentation << nodeContents << endl;
	}

	testTreePrint(rootNode->left, treeLevel + 1);
	testTreePrint(rootNode->right, treeLevel);
	

}
