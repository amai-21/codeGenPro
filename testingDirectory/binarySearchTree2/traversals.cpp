// traversals.cpp
#include <iostream>
#include <vector>
#include <string>
#include "traversals.h"
#include "node.h"

using namespace std;

/*
Level Order traversal code kindly and educationally borrowed from GeeksforGeeks.org
https://www.geeksforgeeks.org/level-order-tree-traversal/#approach-1-using-queue-iterarive-on-time-and-on-space
*/

// Level Order Traversal: Using Stack (Recursive) Approach.

// Helper function for recursive level order traversal
void levelOrderRec(BstNode *root, string::size_type treeLevel, vector<vector<string>>& res){
	// Base case: If node is null, return
	if (root == nullptr) {
		return;
	}

	// Add a new level to the result if needed.
	if (res.size() <= treeLevel) {
		res.push_back({});
	}

	// Add current node's data to its corresonding level
	res[treeLevel].push_back(root->data);

	int indentationLevel = treeLevel * 4;
	string indentation(indentationLevel, ' ');
	cout << indentation << treeLevel << ' ' << root->data << endl;

	// Recur for left and right children nodes:
	levelOrderRec(root->left, treeLevel + 1, res);
	levelOrderRec(root->right, treeLevel + 1, res);

}

// Function to perform level order traversal.
vector<vector<string>> LevelOrder(BstNode *root, string::size_type treeLevel){

	// Stores the result level by level
	vector<vector<string>> res;

	levelOrderRec(root, 0, res);
	return res;
}



void PreOrder(BstNode *root, string::size_type treeLevel){
	if (root == NULL) return; // Base case for this recursive function call.

	// implement the indentation level as a string. I.e., if indentationLevel = 4, indentation will have four empty spaces as a string.
	string::size_type indentationLevel = treeLevel * 4; 
	string indentation(indentationLevel, ' ');

	cout << indentation << treeLevel << ' ' << root->charCount << ' ' <<  root->data << endl; 
	
	PreOrder(root->left, treeLevel + 1);
	PreOrder(root->right, treeLevel + 1);
}

void PostOrder(BstNode *root, string::size_type treeLevel) {
	if (root == NULL) return; // Base case for this recursive function call.

	// Implement the indentation level as a string. I.e., if indentationLevel = 4, indentation will have four empty spaces as a string.
	string::size_type indentationLevel = treeLevel * 4;
	string indentation(indentationLevel, ' ');

	PostOrder(root->left, treeLevel + 1);
	PostOrder(root->right, treeLevel + 1);
	cout << indentation << treeLevel << ' ' << root-> charCount << ' ' << root->data << endl;
}
