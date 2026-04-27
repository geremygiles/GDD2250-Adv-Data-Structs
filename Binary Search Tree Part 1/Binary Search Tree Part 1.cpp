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
    cout << bst.AddNode(4) << endl;

    // Add two new nodes
    cout << bst.AddNode(2) << endl;
    cout << bst.AddNode(6) << endl;

    // Add 4 more nodes
    cout << bst.AddNode(1) << endl;
    cout << bst.AddNode(3) << endl;
    cout << bst.AddNode(5) << endl;
    cout << bst.AddNode(7) << endl;

    BinarySearchTree bst2;

    // Add a node, printing the results
    cout << bst2.AddNode(4) << endl;

    // Add two new nodes
    cout << bst2.AddNode(1) << endl;
    cout << bst2.AddNode(7) << endl;

    // Add 4 more nodes
    cout << bst2.AddNode(2) << endl;
    cout << bst2.AddNode(3) << endl;
    cout << bst2.AddNode(5) << endl;
    cout << bst2.AddNode(6) << endl;


    // Print the tree in order
    cout << bst.PrintTree() << endl;

}