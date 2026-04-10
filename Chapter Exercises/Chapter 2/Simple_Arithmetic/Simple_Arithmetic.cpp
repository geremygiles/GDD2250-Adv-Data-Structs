/*
* Geremy Giles
* Chapter 2, Exercise 2
* Shows simple arithmetic between different simple data types.
*/

#include <iostream>
#include <typeinfo> // Used for outputting type of resulting arithmetic

using namespace std;

int main()
{
    // Creating Variables
    int a = 5;
    int b = 10;
    double d = 12342352;

    float f = 4.25f;

    cout << fixed;

    // Priting Variables
    cout << "Variables" << endl;;

    cout << "a: " << a << ", which is a " << typeid(a).name() << endl
         << "b: " << b << ", which is a " << typeid(b).name() << endl
         << "d: " << d << ", which is a " << typeid(d).name() << endl
         << "f: " << f << ", which is a " << typeid(f).name() << endl;

    cout << endl << endl; // Extra Spacing
    // Printing Outputs of arithmetic
    cout << "Resulting Types:" << endl;

    cout << "a + b: " << (a + b) << ", which is a " << typeid(a + b).name() << endl;
    cout << "a + d: " << (a + d) << ", which is a " << typeid(a + d).name() << endl;
    cout << "a + f: " << (a + f) << ", which is a " << typeid(a + f).name() << endl;
    cout << "d + f: " << (d + f) << ", which is a " << typeid(d + f).name() << endl;

    cout << "a + f: " << static_cast<int>(a + f) << ", when casted as a " << typeid(static_cast<int>(a + f)).name() << endl;
    cout << "d + f: " << static_cast<int>(d + f) << ", when casted as a " << typeid(static_cast<int>(d + f)).name() << endl;
}
