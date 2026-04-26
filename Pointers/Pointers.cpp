/*
* Geremy Giles
* 03/20/2026
* Displays the different use cases of Pointers in C++
*/

#include <iostream>

using namespace std;

int main()
{
    // Creating an integer
    int myInt = 7;
    cout << "MyInt: " << myInt << endl << endl;

    // Creating a pointer to the integer
    int* myIntPointer = &myInt;
    cout << "Address of MyInt: " << &myInt << endl;
    cout << "MyIntPointer: " << myIntPointer << endl;
    cout << "Value at MyIntPointer: " << *myIntPointer << endl << endl;

    // Creating a double pointer that points to the pointer
    int** myDoubleIntPointer = &myIntPointer;
    cout << "Address of MyIntPointer: " << &myIntPointer << endl;
    cout << "MyDoublePointer: " << myDoubleIntPointer << endl;
    cout << "Value at MyDoublePointer: " << *myDoubleIntPointer << endl << endl;


    // Creating a dynamic array using pointers and variable size from a prompt
    cout << "Input the size of the dynamic array: "; // Get user input
    cin >> myInt; // Store in myInt
    int* dynamicArray = new int[myInt]; // Create dynamic array with user's length
    cout << "Created an array 'DynamicArray' with size " << myInt << endl;
    cout << "DynamicArray: " << dynamicArray << endl << endl;

    // Filling the array with values
    cout << "Filled DynamicArray.\nNew Contents: [";
    for (int i = 0; i < myInt; i++)
    {
        dynamicArray[i] = i;
        cout << dynamicArray[i];
        if (i < myInt - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // Creating a new array that is twice as large
    int* doubleSizedArray = new int[myInt * 2];
    cout << "Created an new array 'DoubleSizedArray' with size " << myInt * 2 << endl << endl;
    cout << "DoubleSizedArray: " << doubleSizedArray << endl << endl;

    // Filling the new array with the values of the old
    cout << "Transferring contents of DynamicArray to DoubleSizedArray.\nDoubleSizedArray New Contents: [";
    for (int i = 0; i < myInt; i++) 
    {
        doubleSizedArray[i] = dynamicArray[i];
        cout << doubleSizedArray[i];
        if (i < myInt - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // Deleting the old array
    cout << "Value of DynamicArray pointer: " << dynamicArray << endl;
    delete dynamicArray;
    cout << "DynamicArray deleted." << endl;
    dynamicArray = nullptr;
    cout << "Cleared pointer. Value of DynamicArray pointer: " << dynamicArray << endl << endl;


    // Creating pointers to every other basic data type
    // Characters (ran into a weird behavior where cout was reading the pointer as a c-string, hence the casting to a void pointer.
    char myChar = 'G';
    char* myCharPointer = &myChar;
    cout << "MyChar: " << myChar << endl;
    cout << "Address of MyChar: " << (void*)&myChar << endl;
    cout << "MyCharPointer: " << (void*)myCharPointer << endl;
    cout << "Value at MyCharPointer: " << *myCharPointer << endl << endl;

    // Floats
    float myFloat = 0.1f;
    float* myFloatPointer = &myFloat;
    cout << "MyFloat: " << myFloat << endl;
    cout << "Address of MyFloat: " << &myFloat << endl;
    cout << "MyFloatPointer: " << myFloatPointer << endl;
    cout << "Value at MyFloatPointer: " << *myFloatPointer << endl << endl;

    // Doubles
    double myDouble = 123132424523421;
    double* myDoublePointer = &myDouble;
    cout << "MyDouble: " << myDouble << endl;
    cout << "Address of MyDouble: " << &myDouble << endl;
    cout << "MyDoublePointer: " << myDoublePointer << endl;
    cout << "Value at MyDoublePointer: " << *myDoublePointer << endl << endl;

    // Booleans
    bool myBool = true;
    bool* myBoolPointer = &myBool;
    cout << "MyBool: " << myBool << endl;
    cout << "Address of MyBool: " << &myBool << endl;
    cout << "MyBoolPointer: " << myBoolPointer << endl;
    cout << "Value at MyBoolPointer: " << *myBoolPointer << endl << endl;

}