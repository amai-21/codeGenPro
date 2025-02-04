//node.h
#ifndef NODE_H
#define NODE_H


//Declaring node types code found from Geeksforgeeks.com: https://www.geeksforgeeks.org/introduction-to-binary-tree/
struct node_t{
	int data;
	
	node_t * left, * right;
	node_t (int key) {
		data = key;
		left = nullptr;
		right = nullptr;
	}

	
};

#endif
