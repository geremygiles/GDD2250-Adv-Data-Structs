#include "Node.h"
using namespace std;

int Node::GetData() const
{
	return data;
}

Node* Node::GetLeftNode() const
{
	return leftNode;
}

Node* Node::GetRightNode() const
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

Node::Node(int nodeData)
{
	Node:data = nodeData;
}

Node::Node()
{}
