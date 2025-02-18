// traversals.cpp
#include <iostream>
#include <queue>
#include <string>
#include "traversals.h"
#include "node.h"

using namespace std;

// Learned about the queuing approach through a Youtube video called "Binary tree: Level Order Traversal" by a channel called "mycodeschool".
// https://www.youtube.com/watch?v=86g8jAQug04
void LevelOrder(BstNode *root, int treeLevel, const char[]){
	if (root == NULL) return; // Base case.

	int indentationLevel = treeLevel * 4;
	string indentation(indentationLevel, ' ');
//	cout << indentation << treeLevel << ' ' << root->data << endl;

	queue<BstNode*> levelOrderQueue; // A queue of pointer to node.
	levelOrderQueue.push(root); // Start with the root.

	while(!levelOrderQueue.empty()) { 
		BstNode* current = levelOrderQueue.front(); // Remove front node and print data with correct indentation.
	       	levelOrderQueue.pop();

		indentationLevel = treeLevel * 4;
		string indentation(indentationLevel, ' ');	
		cout << indentation << treeLevel << ' ' << current->data << endl;

		

		// Process all nodes at depth treeLevel before moving on.
		// Add left child to queue (if it exists):
		if (current->left != NULL) {
			levelOrderQueue.push(current ->left); 
		}
		if (current->right != NULL) { // Add right child to queue (if it exists).
			levelOrderQueue.push(current->right);
		}

		treeLevel++;
	}

}



void PreOrder(BstNode *root, int treeLevel){
	if (root == NULL) return; // Base case for this recursive function call.

	// implement the indentation level as a string. I.e., if indentationLevel = 4, indentation will have four empty spaces as a string.
	int indentationLevel = treeLevel * 4; 
	string indentation(indentationLevel, ' ');


	cout << indentation << treeLevel << ' ' << root->charCount << ' ' <<  root->data << endl; 
	cout << endl;

	PreOrder(root->left, treeLevel + 1);
	PreOrder(root->right, treeLevel + 1);
}

void PostOrder(BstNode *root, int treeLevel) {
	if (root == NULL) return; // Base case for this recursive function call.

	// Implement the indentation level as a string. I.e., if indentationLevel = 4, indentation will have four empty spaces as a string.
	int indentationLevel = treeLevel * 4;
	string indentation(indentationLevel, ' ');

//	cout << indentation << treeLevel << ' ' << root->data << endl;
//	cout << endl;

	PostOrder(root->left, treeLevel + 1);
	PostOrder(root->right, treeLevel + 1);
	cout << indentation << treeLevel << ' ' << root->data << endl;
}
