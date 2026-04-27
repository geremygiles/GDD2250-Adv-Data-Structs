/*
* Geremy Giles
* 04/17/2026
* A basic version of a binary search tree. Nodes can be added, removed, printed, and searched for.
*/

#include <iostream>
#include "BinarySearchTree.h"
#include "Node.h"

using namespace std;

int main()
{
    // Create the BST
    BinarySearchTree bst;

    // Add a node, printing the results
    cout << bst.AddNode(3) << endl;

    // Add two new nodes
    cout << bst.AddNode(1) << endl;
    cout << bst.AddNode(2) << endl;

    // Print the tree in order
    cout << bst.PrintTree() << endl;

}