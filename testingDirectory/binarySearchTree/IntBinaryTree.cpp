//IntBinaryTree.cpp
#include <iostream>
#include "IntBinaryTree.h"


using namespace std;

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
	
	if (nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;	
	}
}
