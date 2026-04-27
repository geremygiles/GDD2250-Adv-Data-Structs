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

void Node::SetLeftNode(Node* node)
{
	leftNode = node;
}

void Node::SetRightNode(Node* node)
{
	rightNode = node;
}