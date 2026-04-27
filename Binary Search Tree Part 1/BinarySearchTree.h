#pragma once

#include "Node.h"


class BinarySearchTree
{
private:
	Node* root;
public:
	void AddNode(int nodeData);
	void RemoveNode(Node node);
	void PrintTree();
	bool SearchTree(int nodeValue);
};

