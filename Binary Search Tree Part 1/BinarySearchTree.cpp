#include "BinarySearchTree.h"

#include <string>
#include "Node.h"
using namespace std;

Node* BinarySearchTree::GetRoot()
{
	// Return the root of the tree
	return nullptr;
}

string BinarySearchTree::AddNode(int nodeValue)
{
	// Create a newNode 
	Node* newNode = new Node(nodeValue);

	// Add the newNode to the correct part of the tree
	if (BinarySearchTree::root == nullptr)
	{
		BinarySearchTree::root = newNode;
		return "Successfully added node '" + to_string(nodeValue) + "' to the tree as the root.";
	}

	else
	{
		Node* currentNode = BinarySearchTree::root; // Track the current node
		
		// Iterate through the tree until the correct place is found, then return a string
		while (true)
		{
			// If the new node's value is less than the current node, move to the left side of the current node
			if (newNode->GetData() < currentNode->GetData())
			{
				// Check if there is a value in the left node
				if (currentNode->GetLeftNode() != nullptr) currentNode = currentNode->GetLeftNode();
				//{
				
					//// Check if the new node falls between the current node and the left node
					//if (currentNode->GetLeftNode()->GetData() < newNode->GetData())
					//{
					//	// Check if the branch has a right side, and if so, if the branch should entirely shift left, or if it should be split with the new value
					//	if (currentNode->GetLeftNode()->GetRightNode() != nullptr && currentNode->GetLeftNode()->GetRightNode()->GetData() > newNode->GetData())
					//	{
					//		// Split the branch in half, with the left half (including the center) becoming the new node's left, and the right becoming the new right node.
					//		newNode->SetLeftNode(currentNode->GetLeftNode());
					//		newNode->SetRightNode(currentNode->GetLeftNode()->GetRightNode());

					//		currentNode->SetLeftNode(newNode);

					//		break;
					//	}
					//	else
					//	{
					//		// Shift the entire branch left
					//		newNode->SetLeftNode(currentNode->GetLeftNode());
					//		currentNode->SetLeftNode(newNode);

					//		break;
					//	}
					//}

					//// New node is less than left side, move to the left node
					//else currentNode = currentNode->GetLeftNode();
				//}
				
				// If there is no value in the left node, set the left node to this new node
				else
				{
					currentNode->SetLeftNode(newNode);
					
					break;
				}
			}

			// If the contents are the same, return an error string. (No duplicates allowed)
			else if (newNode->GetData() == currentNode->GetData())
			{
				return "Failed to add node with data '" + to_string(nodeValue) + "'. Duplicate found at node " + to_string(currentNode->GetData());
			}

			// If the new node's value is greater than the current node, move to the right side of the current node
			else
			{
				// Check if there is a value in the right node, if there is, move to that one
				if (currentNode->GetRightNode() != nullptr) currentNode = currentNode->GetRightNode();
				//{

					//// Check if the new node falls between the current node and the right node
					//if (currentNode->GetRightNode()->GetData() > newNode->GetData())
					//{
					//	// Check if the branch has a left side, and if so, if the branch should entirely shift right, or if it should be split with the new value
					//	if (currentNode->GetRightNode()->GetLeftNode() != nullptr && currentNode->GetRightNode()->GetLeftNode()->GetData() < newNode->GetData())
					//	{
					//		// Split the branch in half, with the right half (including the center) becoming the new node's right, and the left becoming the new left node.
					//		newNode->SetRightNode(currentNode->GetRightNode());
					//		newNode->SetLeftNode(currentNode->GetRightNode()->GetLeftNode());

					//		currentNode->SetRightNode(newNode);

					//		break;
					//	}
					//	else
					//	{
					//		// Shift the entire branch right
					//		newNode->SetRightNode(currentNode->GetRightNode());
					//		currentNode->SetRightNode(newNode);
					//		
					//		break;
					//	}
					//}

					//// New node is greater than right side, move to the right node
					//else currentNode = currentNode->GetRightNode();
				//}

				// If there is no value in the right node, set the right node to this new node
				else
				{
					currentNode->SetRightNode(newNode);

					break;
				}
			}
		}
		return "Successfully added the node '" + to_string(nodeValue) + "' to the tree, under the value '" + to_string(currentNode->GetData()) + "'.";
	}
}

string BinarySearchTree::RemoveNode(int nodeValue)
{
	// Declare a flag to track direction of child
	bool isRightNode;
	// Find  the parent
	Node* parentNode = FindNodeParent(nodeValue, isRightNode);
	Node* node = isRightNode ? parentNode->GetRightNode() : parentNode->GetLeftNode();

	// Remove the node from the tree
	return "Remove Node";
}

string BinarySearchTree::PrintTree() const
{
	string finalString = BinarySearchTree::PrintBlock(BinarySearchTree::root);
	finalString = finalString.substr(0, finalString.length() - 2);
	return finalString;
}

string BinarySearchTree::PrintBlock(Node* root) const
{
	// Create string to return
	string returnString = "";

	if (root->GetLeftNode() != nullptr)
	{
		returnString += PrintBlock(root->GetLeftNode());
	}
	
	returnString += to_string(root->GetData()) + ", ";

	if (root->GetRightNode() != nullptr)
	{
		returnString += PrintBlock(root->GetRightNode());
	}
	
	return returnString;
}

bool BinarySearchTree::SearchTree(int nodeValue) const
{
	// Search the tree for a value, and return true if found
	return true;
}

Node* BinarySearchTree::FindNodeParent(int nodeValue, bool& isRightNodeFlag) const
{
	Node* currentNode = BinarySearchTree::root;
	while (true)
	{
		// Desired value is lower than current node
		if (nodeValue < currentNode->GetData())
		{
			if (currentNode->GetLeftNode() != nullptr)
			{
				// If the value is found in one of the children, break the loop at the parent
				if (nodeValue == currentNode->GetLeftNode()->GetData())
				{
					isRightNodeFlag = false;
					break;
				}
				currentNode = currentNode->GetLeftNode();
			}
		}

		// Desired value is greater than current node
		else
		{
			if (currentNode->GetRightNode() != nullptr)
			{
				// If the value is found in one of the children, break the loop at the parent
				if (nodeValue == currentNode->GetRightNode()->GetData())
				{
					isRightNodeFlag = true;
					break;
				}
				currentNode = currentNode->GetRightNode();
			}
		}
	}
	return currentNode;
}