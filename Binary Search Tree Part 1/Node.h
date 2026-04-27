// A node in the binary search tree. Contains data, and two pointers for the next nodes in the tree.

#pragma once

class Node
{
private:
	int data = 0;
	Node* leftNode = nullptr;
	Node* rightNode = nullptr;
public:
	int GetData() const;
	Node* GetLeftNode() const;
	Node* GetRightNode() const;
	void SetLeftNode(Node* node);
	void SetRightNode(Node* node);
	Node(int nodeData);
	Node();
};

