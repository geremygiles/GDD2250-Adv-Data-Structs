/*
* Geremy Giles
* 05/08/2026
* A program that demonstrates reordering an array into a min-heap, and taking in nodes into a priority queue.
*/
#include <iostream>
#include <string>
#include "Output.h"
#include "Priority Queue and Heap.h"

void Heapify(int* heap, int size, int index);

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