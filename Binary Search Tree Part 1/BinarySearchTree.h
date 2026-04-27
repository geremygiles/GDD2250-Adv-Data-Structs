// The binary search tree that holds the nodes. Contains a root and methods for manipulating nodes.

#pragma once
#include "Node.h"
#include <string>

using namespace std;

class BinarySearchTree
{
private:
	Node* root = nullptr;
public:
	Node* GetRoot();

	/// <summary>
	/// Adds the node to the tree in the correct location.
	/// </summary>
	/// <param name="nodeData">The data to add to the tree.</param>
	/// <returns>Returns the results of the add.</returns>
	string AddNode(int nodeData);
	string RemoveNode(Node node);
	string PrintTree() const;
	bool SearchTree(int nodeValue) const;
};

