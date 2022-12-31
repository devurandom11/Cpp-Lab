// Write a program that removes all non-alphabetic characters from the given input.

// Ex: If the input is:

// -Hello, 1 world$!

// the output is:

// Helloworld

// Your program must define and call the following function that takes a string as a parameter and returns the string without any non-alphabetic characters.
// string RemoveNonAlpha(string userString)

#include <iostream>
#include <string>
using namespace std;

string RemoveNonAlpha(string userString)
{
    unsigned int i;
    for (i = 0; i < userString.size(); i++)
    {
        if (!isalpha(userString.at(i)))
        {
            userString.replace(i, 1, "");
            i--;
        }
    }
    return userString;
}

int main()
{
    string userString;
    string newString;
    getline(cin, userString);
    newString = RemoveNonAlpha(userString);
    cout << newString << endl;

    return 0;
}
