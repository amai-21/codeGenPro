//buildTree.cpp
#include <iostream>
#include <string>
#include <vector>
#include "buildTree.h"
#include "node.h"

node_t* GetNewNode(string data, string::size_type charCount) {
	node_t* newNode = new node_t();
	newNode->data = data;
	newNode->charCount = charCount;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//Function that recursively calls itself when inserting a new node.
//node_t* Insert(node_t* root, string data, int charCount) { // empty tree
node_t* Insert(node_t* root, string data, string::size_type charCount) {	
	if (root == NULL) {
		charCount = data.size();	
		root = GetNewNode(data, charCount);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data, charCount);
	}
	else {
		root->right = Insert(root->right, data, charCount);
	}
	return root;
}
