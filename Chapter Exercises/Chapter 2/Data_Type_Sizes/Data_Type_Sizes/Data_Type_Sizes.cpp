/*
* Geremy Giles
* Chapter 2, Exercise 1
* Shows the data type and the size of the type when stored in memory.
*/
#include <iostream>

using namespace std;

int main()
{
    bool b;
    char c;
    int i;
    short int si;
    long int li;
    long long int lli;
    double d;
    long double ld;
    float f;
    cout << "Data Type Sizes:" << endl << endl;

    cout << "Boolean: " << sizeof(b) << " byte" << endl;
    cout << "Char: " << sizeof(c) << " byte" << endl;
    cout << "Integer: " << sizeof(i) << " bytes" << endl;
    cout << "Short Integer: " << sizeof(si) << " bytes" << endl;
    cout << "Long Integer: " << sizeof(li) << " bytes" << endl;
    cout << "Long Long Integer: " << sizeof(lli) << " bytes" << endl;
    cout << "Double: " << sizeof(d) << " bytes" << endl;
    cout << "Long Double: " << sizeof(ld) << " bytes" << endl;
    cout << "Float: " << sizeof(f) << " bytes" << endl;
}