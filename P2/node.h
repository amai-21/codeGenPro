//node.h
#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>

using namespace std;

struct node_t {
	string data;
	vector<string> stringsSeen; // A list (vector) of strings already seen that have the same number of characters.
	string::size_type charCount; // The number of characters in the string.
	
	// Two child nodes (left and right)
	node_t *left;
        node_t *right; 	
	
};

#endif
