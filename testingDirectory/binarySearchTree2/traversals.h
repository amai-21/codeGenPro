// traversals.h
#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include <vector>
#include "node.h"

void LevelOrder(BstNode *root, int treeLevel);
void levelOrderRec(BstNode *root, int treeLevel, vector<vector<string>>& res);
void PreOrder(BstNode *root, int treeLevel);
void PostOrder(BstNode *root, int treeLevel);

#endif
