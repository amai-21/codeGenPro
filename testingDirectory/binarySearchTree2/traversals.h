// traversals.h
#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include <vector>
#include <string> // using string::size_type to avoid complications with comparing ints and unsigned ints.
#include "node.h"

vector<vector<string>> LevelOrder(BstNode *root, string::size_type treeLevel);
void levelOrderRec(BstNode *root, string::size_type treeLevel, vector<vector<string>>& res);
void PreOrder(BstNode *root, string::size_type treeLevel);
void PostOrder(BstNode *root, string::size_type treeLevel);

#endif
