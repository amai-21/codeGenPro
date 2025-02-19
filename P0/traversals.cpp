//traversals.cpp
#include <iostream>
#include <vector>
#include <string>
#include "node.h"
#include "traversals.h"

// Level Order traversal code kindly and educationally borrowed from GeeksforGeeks.org
// https://www.geeksforgeeks.org/level-order-tree-traversal/

// Helper function for recursive level order traversal
void levelOrderRec(node_t* root, string::size_type treeLevel, vector<vector<string>>& res){
	// Base case: If node is null, return
	if (root == nullptr) return;

	// Add a new level to the result if needed.
	if (res.size() <= treeLevel)
		res.push_back({});

	// Add current node's data to its corresponding level
	res[treeLevel].push_back(root->data);

	int indentationLevel = treeLevel * 4;
	string indentation(indentationLevel, ' ');
	cout << indentation << treeLevel << ' ' << root->data << endl;

	// Recur for left and right children
	levelOrderRec(root->left, treeLevel + 1, res);
	levelOrderRec(root->right, treeLevel + 1, res);
}

vector<vector<string>> traverseLevelOrder(node_t* root, string::size_type treeLevel){
	// Stores the result level by level
	vector<vector<string>> res;

	levelOrderRec(root, 0, res);
	return res;
	
}

void traversePreOrder(node_t* root, string::size_type treeLevel, ofstream &outputFile){
	if (root == NULL) return; // Base case for this recursive function call.

	// Implement the indentation level as a string. I.e., if indentationLevel = 4, indentation will have four empty spaces as a string.
	string::size_type indentationLevel = treeLevel * 4;
	string indentation(indentationLevel, ' ');

	cout << indentation << treeLevel << ' ' << root->charCount << ' ' << root->data << endl;

	outputFile << indentation << treeLevel << ' ' << root->charCount << ' ' << root->data << endl;
	
	traversePreOrder(root->left, treeLevel + 1, outputFile);
	traversePreOrder(root->right, treeLevel + 1, outputFile);
}

void traversePostOrder(node_t* root, string::size_type treeLevel){
	if (root==NULL) return; // Base case for this recursive function call.

	// Implement the indentation level as a stirng. I.e., if indentationLevel = 4, indentation will have four empty spaces as a string.
	string::size_type indentationLevel = treeLevel * 4;
	string indentation(indentationLevel, ' ');

	traversePostOrder(root->left, treeLevel + 1);
	traversePostOrder(root->right, treeLevel + 1);
	cout << indentation << treeLevel << ' ' << root->charCount << ' ' << root->data << endl;
}
