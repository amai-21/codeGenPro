//node.h
#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>

using namespace std;

struct BstNode {
	string data;
	vector<string> stringsSeen; // A list (vector) of strings already seen that have the same number of characters.	
	int charCount; // The number of characters in the string.

	// Two child nodes (left and right)
	BstNode *left;
	BstNode *right;
};

#endif
