//buildTree.cpp
#include <iostream>
#include <string>
#include <vector>
#include "buildTree.h"
#include "node.h"

node_t* GetNewNode(string data, string::size_type charCount, vector<string> stringsSeen) {
//node_t* GetNewNode(string::size_type charCount, vector<string> stringsSeen) {
	node_t* newNode = new node_t();
	newNode->data = data;
	newNode->charCount = charCount;
	newNode->left = newNode->right = NULL;
	newNode->stringsSeen = stringsSeen;
	return newNode;
}

//Function that recursively calls itself when inserting a new node.
//node_t* Insert(node_t* root, string data, int charCount) { // empty tree
node_t* Insert(node_t* root, string data, string::size_type charCount, vector<string> stringsSeen) {	
//node_t* Insert(node_t* root, string::size_type charCount, vector<string> stringsSeen) {

	if (root == NULL) { // base case
		root = GetNewNode(data, charCount, stringsSeen);
		//root = GetNewNode(charCount, stringsSeen);	
	}
//	else if (data <= root->data) {
	else if (charCount < root->charCount) { // Store in left sub tree
		//root->left = Insert(root->left, data, charCount, stringsSeen[i]);
	//	cout << charCount << " " << data << endl;
		
		root->left = Insert(root->left, data, charCount, stringsSeen);
	}
	else if(charCount > root->charCount) { // Store in right subtree 
		//root->right = Insert(root->right, data, charCount, stringsSeen[i]);
		root->right = Insert(root->right, data, charCount, stringsSeen);

	} else if (charCount == root->charCount) { // If same char count, append to stringsSeen (handling duplicates)
		root->stringsSeen.push_back(data);
	//	return root;
	}
	return root;
}
