//main.cpp
#include <iostream>
#include <fstream>
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

//	const int charCount = 0;

	string s1 = "cad";
	string s2 = "fadf";
	string s3 = "baaaaad";
	string s4 = "Hello";
	string s5 = "Sad";
	string s6 = "Strad";

	// while loop when calling Insert function.


	root = Insert(root, s1, s1.size());
//	cout << "character count of cad: " << root->charCount << endl;
	root = Insert(root, "fadf", s2.size());
//	cout << "character count of fadf: " << root->charCount << endl;
	root = Insert(root, "baaaaad", s3.size());
//	cout << "character count of baaaad: " << root->charCount << endl;
	root = Insert(root, s4, s4.size());
	root = Insert(root, s5, s5.size());
	root = Insert(root, s6, s6.size());

//	root = Insert(root,"bad", charCount);
//	root = Insert(root, "crad", charCount);
//	root = Insert(root, "lad", charCount);
//	root = Insert(root, "plad", charCount);

	// Create output file for Level Order.
//	ofstream levelOrderFile("test.levelorder");


	PreOrder(root, treeLevel);
	cout << "<------------------------------------------------------->" << endl << "Postorder tree printing." << endl;
	PostOrder(root, treeLevel);
	cout << "<------------------------------------------------------->" << endl << "Level Order tree printing." << endl;
	LevelOrder(root, treeLevel);

//	cout << root->data;

	

	return 0;
}
