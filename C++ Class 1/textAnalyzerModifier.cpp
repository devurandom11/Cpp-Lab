// (1) Prompt the user to enter a string of their choosing. Output the string. (1 pt)

// Ex:

// Enter a sentence or phrase:
// The only thing we have to fear is fear itself.

// You entered: The only thing we have to fear is fear itself.

// (2) Complete the GetNumOfCharacters() function, which returns the number of characters in the user's string. We encourage you to use a for loop in this function. (2 pts)

// (3) In main(), call the GetNumOfCharacters() function and then output the returned result. (1 pt)

// (4) Implement the OutputWithoutWhitespace() function. OutputWithoutWhitespace() outputs the string's characters except for whitespace (spaces, tabs). Note: A tab is '\t'. Call the OutputWithoutWhitespace() function in main(). (2 pts)

// Ex:

// Enter a sentence or phrase:
// The only thing we have to fear is fear itself.

// You entered: The only thing we have to fear is fear itself.

// Number of characters: 46
// String with no whitespace: Theonlythingwehavetofearisfearitself.

#include <iostream>
#include <string>
using namespace std;

int GetNumOfCharacters(const string usrStr)
{
    return usrStr.size();
}

string OutputWithoutWhitespace(string usrStr)
{
    unsigned int i;
    for (i = 0; i < usrStr.size(); i++)
    {
        if (isspace(usrStr.at(i)))
        {
            usrStr.replace(i, 1, "");
            i--;
        }
    }
    return usrStr;
}

int main()
{
    string usrStr;
    int strLength;
    string newStr;

    cout << "Enter a sentence or phrase:" << endl;
    getline(cin, usrStr);
    cout << endl;
    cout << "You entered: " << usrStr << endl;
    strLength = GetNumOfCharacters(usrStr);
    cout << endl;
    cout << "Number of characters: " << strLength << endl;
    newStr = OutputWithoutWhitespace(usrStr);
    cout << "String with no whitespace: " << newStr << endl;

    return 0;
}