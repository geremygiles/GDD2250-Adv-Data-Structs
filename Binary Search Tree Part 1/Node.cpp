// A node in the binary search tree. Contains data, and two pointers for the next nodes in the tree.

#include "Node.h"
using namespace std;

int Node::GetData()
{
	return data;
}

Node* Node::GetLeftNode()
{
	return leftNode;
}

Node* Node::GetRightNode()
{
	return rightNode;
}