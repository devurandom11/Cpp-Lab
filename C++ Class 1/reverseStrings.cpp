
// 4.24 LAB: Print string in reverse

// Write a program that takes in a line of text as input, and outputs that line of text in reverse. The program repeats, ending when the user enters "Done", "done", or "d" for the line of text.

// Ex: If the input is:

// Hello there
// Hey
// done

// then the output is:

// ereht olleH
// yeH

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i;
    string userInput;
    string reverseString;

    getline(cin, userInput);
    while ((userInput != "done") && (userInput != "Done") && (userInput != "d"))
    {
        reverseString = "";
        for (i = userInput.length() - 1; i >= 0; i--)
        {
            reverseString += userInput[i];
        }
        cout << reverseString << endl;
        getline(cin, userInput);
    }

    return 0;
}
