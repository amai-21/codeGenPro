//buildTree.cpp
#include <iostream>
#include <string>
#include "buildTree.h"
#include "node.h"

node_t* GetNewNode(string data, int charCount) {
	node_t* newNode = new node_t();
	newNode->data = data;
	newNode->charCount = charCount;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//Function that recursively calls itself when inserting a new node.
node_t* Insert(node_t* root, string data, int charCount) { // empty tree
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
