// The binary search tree that holds the nodes. Contains a root and methods for manipulating nodes.

#pragma once
#include "Node.h"
#include <string>

using namespace std;

class BinarySearchTree
{
private:
	Node* root = nullptr;
	string PrintBlock(Node* root) const;
public:
	Node* GetRoot();
	 
	/// <summary>
	/// Adds the node to the tree in the correct location.
	/// </summary>
	/// <param name="nodeValue">The data to add to the tree.</param>
	/// <returns>Returns the results of the add.</returns>
	string AddNode(int nodeValue);
	string RemoveNode(int nodeValue);
	string PrintTree() const;
	bool SearchTree(int nodeValue) const;
	Node* FindNodeParent(int nodeValue, bool& isRightNodeFlag) const;
};

