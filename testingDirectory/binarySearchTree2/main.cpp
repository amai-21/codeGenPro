//main.cpp
#include <iostream>
#include "binarySearchTree.h"
#include "traversals.h"
#include "node.h"

using namespace std;

int main(int argc, char* argv[]){

	BstNode* root = NULL; // Creating an empty tree.
//	root = Insert(root,15);
//	root = Insert(root,10);
//	root = Insert(root, 6);
	//Print Nodes in level order:
//	LevelOrder(root);

	cout << "<------------------------------------------------------>" << endl;

	cout << "Preorder tree printing:\n";

	const int treeLevel = 0;

	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 6);
	root = Insert(root, 1);
	root = Insert(root, 25);
	root = Insert(root, 17);
	root = Insert(root, 30);

	PreOrder(root, treeLevel);
	cout << "<------------------------------------------------------->" << endl << "Postorder tree printing." << endl;
	PostOrder(root, treeLevel);
	cout << "<------------------------------------------------------->" << endl << "Level Order tree printing." << endl;
	LevelOrder(root, treeLevel);

	return 0;
}
