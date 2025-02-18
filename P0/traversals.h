//traversals.h

#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include <vector>
#include <string> // using string::size_type to avoid complications with comparing ints and unsigned ints.
#include "node.h"

void levelOrderRec(node_t* root, string::size_type treeLevel, vector<vector<string>>& res); // Helper function for recursive level order traversal. 
vector<vector<string>> traverseLevelOrder(node_t* root, string::size_type treeLevel);
void traversePreOrder(node_t*, string::size_type treeLevel);
void traversePostOrder(node_t*, string::size_type treeLevel);

#endif
