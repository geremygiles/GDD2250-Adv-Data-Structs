/*
* Geremy Giles
* 05/08/2026
* A program that demonstrates reordering an array into a min-heap, and taking in nodes into a priority queue.
*/
#include <iostream>
#include <string>
#include "Output.h"
#include "Node.h"
#include "Priority Queue and Heap.h"

void Heapify(int* heap, int size, int index);
void AddNode(Node* node, Node* queue[], int index);
void PullUp(Node* heap[], int index);

int main()
{
    Output out;

    int size = out.PromptInt("Specify the length of the array.");

    int* heap = new int[size];

    for (int i = 0; i < size; i++)
    {
        heap[i] = out.PromptInt("Enter an integer for the array.");
    }

    out.PrintArray(heap, size);
    
    // Get starting index for heapifying
    int index = (size/2) - 1;

    while (index >= 0)
    {
        Heapify(heap, size, index);

        // Decrement index
        index--;
    }

    out.PrintArray(heap, size);

    // Priority Queue Example
    out.PrintQueueIntro();

    // Create queue
    Node* queue[3];

    // Create first node
    AddNode(new Node("I am the first node! My priority is 3.", 3), queue, 0);

    // Create second node
    AddNode(new Node("I am the second node! My priority is 1.", 1), queue, 1);

    // Create third node
    AddNode(new Node("I am the third node! My priority is 2.", 2), queue, 2);

    out.PrintQueue(queue);
}

void Heapify(int* heap, int size, int index)
{
    int currentValue = heap[index];
    int leftIndex = (index * 2) + 1;
    int rightIndex = (index * 2) + 2;

    // Check against children to find smallest value
    int smallestValueIndex = index;

    // Check against children
    if (leftIndex < size && heap[leftIndex] < heap[smallestValueIndex])
    {
        smallestValueIndex = leftIndex;
    }

    if (rightIndex < size && heap[rightIndex] < heap[smallestValueIndex])
    {
        smallestValueIndex = rightIndex;
    }

    if (smallestValueIndex != index)
    {
        // Swap the value at index with the value at smallestValueIndex
        int temp = heap[index];
        heap[index] = heap[smallestValueIndex];
        heap[smallestValueIndex] = temp;

        Heapify(heap, size, smallestValueIndex);
    }
}

void AddNode(Node* node, Node* queue[], int index)
{
    queue[index] = node;

    PullUp(queue, index);
}

void PullUp(Node* heap[], int index)
{
    if (index == 0) return;

    int parentIndex = (index - 1) / 2;

    if (heap[index]->GetPriority() < heap[parentIndex]->GetPriority())
    {
        // Swap the value at index with the value at parent
        Node* temp = heap[index];
        heap[index] = heap[parentIndex];
        heap[parentIndex] = temp;

        PullUp(heap, parentIndex);
    }
}