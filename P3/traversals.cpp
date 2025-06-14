//traversals.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "node.h"
#include "traversals.h"


// Level Order traversal code kindly and educationally borrowed from GeeksforGeeks.org
// https://www.geeksforgeeks.org/level-order-tree-traversal/

// Helper function for recursive level order traversal
void levelOrderRec(node_t* root, string::size_type treeLevel, vector<vector<string>>& res, ofstream &outputFile){
	// Base case: If node is null, return
	if (root == nullptr) return;

	// Add a new level to the result if needed.
	if (res.size() <= treeLevel)
		res.push_back({});

	// Add current node's data to its corresponding level
	res[treeLevel].push_back(root->data);

	// Recur for left and right children
	levelOrderRec(root->left, treeLevel + 1, res, outputFile);
	levelOrderRec(root->right, treeLevel + 1, res, outputFile);
}

vector<vector<string>> traverseLevelOrder(node_t* root, string::size_type treeLevel, ofstream &outputFile){
	// Stores the result level by level
	vector<vector<string>> res;

	levelOrderRec(root, 0, res, outputFile);

	// Iterative approach to level order printing borrowed from geeksfromgeeks.org: https://www.geeksforgeeks.org/print-level-order-traversal-line-line/ 
	// Print results after traversal
	for (string::size_type treeLevel = 0; treeLevel < res.size(); treeLevel++) {
		string::size_type indentationLevel = treeLevel * 4;
		string indentation(indentationLevel, ' ');

		for (const string& val : res[treeLevel]) {
			// Character processing code kindly and educationally borrowed from C++ Primer textbook written in 2013.
			string word = ""; // Extract beginning word before calculating correct char counts.
			for (char c : val) { 
				if (c == ' ') {
					break; // Stop at first space.
				}
				word += c;
			}
			string::size_type charCount = word.size();

			outputFile << indentation << treeLevel << ' ' << charCount << ' ' << val << endl;
		}
	}	

	return res;
}

// Recursive preorder traversal function call.
void traversePreOrder(node_t* root, string::size_type treeLevel, ofstream &outputFile){
	if (root == NULL) return; // Base case for this recursive function call.

	// Implement the indentation level as a string. I.e., if indentationLevel = 4, indentation will have four empty spaces as a string.
	string::size_type indentationLevel = treeLevel * 4;
	string indentation(indentationLevel, ' ');

	outputFile << indentation << treeLevel << ' ' << root->charCount << ' ' << root->data << endl;
	outputFile.flush(); // Force immediate write to save data 

	traversePreOrder(root->left, treeLevel + 1, outputFile);
	traversePreOrder(root->right, treeLevel + 1, outputFile);
}

// Recursive Post Order traversal function call.
void traversePostOrder(node_t* root, string::size_type treeLevel, ofstream &outputFile){
	if (root==NULL) return; // Base case for this recursive function call.

	// Implement the indentation level as a string. I.e., if indentationLevel = 4, indentation will have four empty spaces as a string.
	string::size_type indentationLevel = treeLevel * 4;
	string indentation(indentationLevel, ' ');

	traversePostOrder(root->left, treeLevel + 1, outputFile);
	traversePostOrder(root->right, treeLevel + 1, outputFile);
	
	outputFile << indentation << treeLevel << ' ' << root->charCount << ' ' << root->data << endl;
	outputFile.flush(); // Force immediate write to save data.
}
