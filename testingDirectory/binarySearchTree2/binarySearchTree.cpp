// binarySearchTree.cpp
#include <iostream>
#include <string>
#include "binarySearchTree.h"
#include "node.h"

BstNode* GetNewNode(string data, int charCount) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->charCount = charCount;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, string data, int charCount) { // empty tree
	if (root == NULL) { 
		charCount = data.size();
		root = GetNewNode(data, charCount);

	}
	else if (data <= root->data) {
	//	root->charCount = data.size();			
		root->left = Insert(root->left, data, charCount);
	}
	else {
	//	root->charCount = data.size();	
		root->right = Insert(root->right, data, charCount);
	}
	return root;
}
