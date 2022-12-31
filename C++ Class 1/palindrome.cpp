// A palindrome is a word or a phrase that is the same when read both forward and backward. Examples are: "bob," "sees," or "never odd or even" (ignoring spaces). Write a program whose input is a word or phrase, and that outputs whether the input is a palindrome.

// Ex: If the input is:

// bob

// the output is:

// palindrome: bob

// Ex: If the input is:

// bobby

// the output is:

// not a palindrome: bobby

// Hint: Start by just handling single-word input, and submit for grading. Once passing single-word test cases, extend the program to handle phrases. If the input is a phrase, remove or ignore spaces.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    unsigned int i;
    int j;
    string userInput;
    string strippedInput;
    string reverseInput;

    getline(cin, userInput);

    // Remove spaces
    for (i = 0; i < userInput.size(); i++)
    {
        if (userInput.at(i) != ' ')
        {
            strippedInput += userInput.at(i);
        }
    }
    // Reverse string
    for (j = strippedInput.size() - 1; j >= 0; j--)
    {
        reverseInput += strippedInput.at(j);
    }

    // Check reverse string vs stripped string
    if (strippedInput == reverseInput)
    {
        cout << "palindrome: " << userInput << endl;
    }
    else
    {
        cout << "not a palindrome: " << userInput << endl;
    }

    return 0;
}
