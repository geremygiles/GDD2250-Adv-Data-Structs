/*
* Geremy Giles
* Chapter 4, Exercise 1: String Comparisons
* Shows the different kinds of outcomes when comparing strings.
*/

#include <iostream>
#include <string> // Allows use of strings

using namespace std;

int main()
{
    // Declare strings
    string lowValueChar = "a";
    string highValueChar = "z";

    string lowercaseChar = "g";
    string uppercaseChar = "G";

    string shortGreeting = "Hey!";
    string longGreeting = "Good morning!";

    string question = "I think so?";
    string exclamation = "I think so!";

    // Compare strings and display results

    cout << "Is a low decimal value character greater than a high decimal value character?" << endl;
    cout << "\"" << lowValueChar << "\" > \"" << highValueChar << "\" -> " << ((lowValueChar > highValueChar) ? "True!" : "False!") << endl;
    cout << "Why? Because the decimal value of 'a' (97), is less than the decimal value of 'z' (122)." << endl << endl;

    cout << "Is a lowercase character greater than an uppercase character?" << endl;
    cout << "\"" << lowercaseChar << "\" > \"" << uppercaseChar << "\" -> " << ((lowercaseChar > uppercaseChar) ? "True!" : "False!") << endl;
    cout << "Why? Because the uppercase letters are of lower value than the lowercase ones." << endl << endl;

    cout << "Is a short string greater than a long string?" << endl;
    cout << "\"" << shortGreeting << "\" > \"" << longGreeting << "\" -> " << ((shortGreeting > longGreeting) ? "True!" : "False!") << endl;
    cout << "Why? Because the decimal value of 'H' (72) is greater than the decimal value of 'G' (71)." << endl << endl;

    cout << "Is a question mark greater than an exclamation mark?" << endl;
    cout << "\"" << question << "\" > \"" << exclamation << "\" -> " << ((question > exclamation) ? "True!" : "False!") << endl;
    cout << "Why? Because the decimal value of '?' (63), is less than the decimal value of '!' (33)." << endl << endl;

}
