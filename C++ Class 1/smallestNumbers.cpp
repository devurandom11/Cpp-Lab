
// 5.21 LAB: Two smallest numbers

// Write a program that reads a list of integers, and outputs the two smallest integers in the list, in ascending order. The input begins with an integer indicating the number of integers that follow.

// Ex: If the input is:

// 5
// 10 5 3 21 2

// the output is:

// 2 and 3

// You can assume that the list of integers will have at least 2 values.

// To achieve the above, first read the integers into a vector.

// Hint: Make sure to initialize the second smallest and smallest integers properly.

// 5.21 LAB: Two smallest numbers

// Write a program that reads a list of integers, and outputs the two smallest integers in the list, in ascending order. The input begins with an integer indicating the number of integers that follow.

// Ex: If the input is:

// 5
// 10 5 3 21 2

// the output is:

// 2 and 3

// You can assume that the list of integers will have at least 2 values.

// To achieve the above, first read the integers into a vector.

// Hint: Make sure to initialize the second smallest and smallest integers properly.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    unsigned int i;
    unsigned int j;
    int userInput;
    int userInputs;
    int smallestNum;
    vector<int> userList;

    cin >> userInput;
    for (int i = 0; i < userInput; i++)
    {
        cin >> userInputs;
        userList.push_back(userInputs);
    }

    for (i = 0; i < userList.size(); i++)
    {
        smallestNum = userList.at(i);
        for (j = i + 1; j < userList.size(); j++)
        {
            if (userList.at(j) < userList.at(i))
            {
                smallestNum = userList.at(j);
                userList.at(j) = userList.at(i);
                userList.at(i) = smallestNum;
            }
        }
    }
    cout << userList.at(0) << " and " << userList.at(1) << endl;

    return 0;
}