//buildTree.h

#ifndef BUILDTREE_H
#define BUILDTREE_H
#include "node.h"
#include <string>

//node_t* buildTree(FILE *);
node_t* Insert(node_t* root, string data, int charCount);
node_t* GetNewNode(string data, int charCount);

#endif
