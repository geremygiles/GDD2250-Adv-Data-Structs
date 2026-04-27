#include "BinarySearchTree.h"

#include <string>
#include "Node.h"
using namespace std;

Node* BinarySearchTree::GetRoot()
{
	// Return the root of the tree
	return nullptr;
}

string BinarySearchTree::AddNode(int nodeData)
{
	// Create a newNode 
	Node* newNode = new Node(nodeData);

	// Add the newNode to the correct part of the tree
	if (BinarySearchTree::root == nullptr)
	{
		BinarySearchTree::root = newNode;
		return "Successfully added node '" + to_string(nodeData) + "' to the tree as the root.";
	}

	else
	{
		Node* currentNode = BinarySearchTree::root; // Track the current node
		
		// Iterate through the tree until the correct place is found
		bool placeFound = false;
		while (!placeFound)
		{
			// If the new node's value is less than the current node, move to the current node's left node
			if (newNode->GetData() < currentNode->GetData())
			{
				// If there is a value in the left node, move to that node
				if (currentNode->GetLeftNode() != nullptr) currentNode = currentNode->GetLeftNode();
				
				// If there is no value in the left node, set the left node to this new node
				else
				{
					placeFound = true;
					currentNode->SetLeftNode(newNode);
				}
			}

			// If the contents are the same, return an error string. (No duplicates allowed)
			else if (newNode->GetData() == currentNode->GetData())
			{
				return "Failed to add node with data '" + to_string(nodeData) + "'. Duplicate found at node " + to_string(currentNode->GetData());
			}

			// If greater, move to the current node's right node
			else
			{
				// If there is a value in the left node, move to that node
				if (currentNode->GetRightNode() != nullptr) currentNode = currentNode->GetRightNode();
				
				// If there is no value in the left node, set the left node to this new node
				else
				{
					placeFound = true;
					currentNode->SetRightNode(newNode);
				}
			}
		}
		return "Successfully added the node '" + to_string(nodeData) + "' to the tree, under the value '" + to_string(currentNode->GetData()) + "'.";
	}
}

string BinarySearchTree::RemoveNode(Node node)
{
	// Remove the node from the tree
	return "Remove Node";
}

string BinarySearchTree::PrintTree() const
{
	// Print the contents of the tree in order
	return "Here's da tree";
}

bool BinarySearchTree::SearchTree(int nodeValue) const
{
	// Search the tree for a value, and return true if found
	return true;
}