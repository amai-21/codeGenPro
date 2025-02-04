//traversals.cpp
#include "traversals.h"

// Helper function for recursive level order traversal:
void levelOrderRec(node_t*, root, int level, vector<vector<int>>& res){
	// Base case: If node is null, return
	if (root == nullptr) return;

	// Add a new level to the result if needed.
	if (res.size() <= level)
		res.push_back({});

	// Add current node's data to its corresponding level
	res[level].push_back(root->data);

	// Recur for left and right children
	levelOrderRec(root->left, level + 1, res);
	levelOrderRec(root->right, level + 1, res);
}

void traverseLevelOrder(node_t* root){
	// Stores the result level by level
	vector<vector<int>> res;

	levelOrderRec(root, 0, res);
	return res;
	
}

void traversePreOrder(node_t*, const char[]){

}

void traversePostOrder(node_t*, const char[]){

}
