/*
* Geremy Giles
* 04/17/2026
* A basic version of a binary search tree. Nodes can be added, removed, printed, and searched for.
*/

#include <iostream>
#include "BinarySearchTree.h"
#include "Node.h"

using namespace std;

//int main()
//{
//    // Create the BST
//    BinarySearchTree bst;
//
//    // Add a node, printing the results
//    cout << bst.AddNode(4) << endl;
//
//    // Add two new nodes
//    cout << bst.AddNode(2) << endl;
//    cout << bst.AddNode(6) << endl;
//
//    // Add 4 more nodes
//    cout << bst.AddNode(1) << endl;
//    cout << bst.AddNode(3) << endl;
//    cout << bst.AddNode(5) << endl;
//    cout << bst.AddNode(7) << endl;
//
//    BinarySearchTree bst2;
//
//    // Add a node, printing the results
//    cout << bst2.AddNode(4) << endl;
//
//    // Add two new nodes
//    cout << bst2.AddNode(1) << endl;
//    cout << bst2.AddNode(7) << endl;
//
//    // Add 4 more nodes
//    cout << bst2.AddNode(2) << endl;
//    cout << bst2.AddNode(3) << endl;
//    cout << bst2.AddNode(5) << endl;
//    cout << bst2.AddNode(6) << endl;
//
//
//    // Print the tree in order
//    cout << bst.PrintTree() << endl;
//    cout << bst2.PrintTree() << endl;
//}

int main()
{
	BinarySearchTree bushyBst;

	// Level 0: The Root (The ultimate middle)
	cout << bushyBst.AddNode(8) << endl;

	// Level 1: The middle of the left and right halves
	cout << bushyBst.AddNode(4) << endl;
	cout << bushyBst.AddNode(12) << endl;

	// Level 2: Middle of the four remaining quarters
	cout << bushyBst.AddNode(2) << endl;
	cout << bushyBst.AddNode(6) << endl;
	cout << bushyBst.AddNode(10) << endl;
	cout << bushyBst.AddNode(14) << endl;

	// Level 3: The Leaves (The remaining odd numbers)
	cout << bushyBst.AddNode(1) << endl;
	cout << bushyBst.AddNode(3) << endl;
	cout << bushyBst.AddNode(5) << endl;
	cout << bushyBst.AddNode(7) << endl;
	cout << bushyBst.AddNode(9) << endl;
	cout << bushyBst.AddNode(11) << endl;
	cout << bushyBst.AddNode(13) << endl;
	cout << bushyBst.AddNode(15) << endl;

	cout << bushyBst.PrintTree() << endl;

	BinarySearchTree diamondBst;

	// The "Spine"
	cout << diamondBst.AddNode(50) << endl; // Root
	cout << diamondBst.AddNode(25) << endl; // Left Child
	cout << diamondBst.AddNode(75) << endl; // Right Child

	// The "Width" - Branching off the children
	cout << diamondBst.AddNode(15) << endl; // Left of 25
	cout << diamondBst.AddNode(35) << endl; // Right of 25
	cout << diamondBst.AddNode(65) << endl; // Left of 75
	cout << diamondBst.AddNode(85) << endl; // Right of 75

	// The "Inner Branching" - Pushing nodes into the gaps
	cout << diamondBst.AddNode(30) << endl; // Left of 35
	cout << diamondBst.AddNode(40) << endl; // Right of 35
	cout << diamondBst.AddNode(60) << endl; // Left of 65
	cout << diamondBst.AddNode(70) << endl; // Right of 65

	cout << diamondBst.PrintTree() << endl;
}