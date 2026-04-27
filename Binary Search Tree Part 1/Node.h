#pragma once
class Node
{
private:
	int data;
	Node* leftNode;
	Node* rightNode;
public:
	int GetData();
	int GetLeftNode();
	int GetRightNode();
};

