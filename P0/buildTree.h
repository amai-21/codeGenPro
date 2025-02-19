//buildTree.h

#ifndef BUILDTREE_H
#define BUILDTREE_H
#include "node.h"
#include <string>
#include <vector>

node_t* Insert(node_t* root, string data, string::size_type charCount, vector<string> stringsSeen);
node_t* GetNewNode(string data, string::size_type charCount, vector<string> stringsSeen);

#endif
