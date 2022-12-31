// Define a function named SwapValues that takes four integers as parameters and swaps the first with the second, and the third with the fourth values. Then write a main program that reads four integers from input, calls function SwapValues() to swap the values, and prints the swapped values on a single line separated with spaces.

// Ex: If the input is:

// 3 8 2 4

// function SwapValues() returns and the main program outputs:

// 8 3 4 2

// The program must define and call a function:
// void SwapValues(int& userVal1, int& userVal2, int& userVal3, int& userVal4)
// Function SwapValues() swaps the values referenced by the parameters.

#include <iostream>

using namespace std;

// void SwapValues(int &userVal1, int &userVal2, int &userVal3, int &userVal4)
// {
//     int temp;
//     temp = userVal2;
//     userVal2 = userVal1;
//     userVal1 = temp;
//     temp = userVal4;
//     userVal4 = userVal3;
//     userVal3 = temp;
// }

// XOR solution
void SwapValues(int &userVal1, int &userVal2, int &userVal3, int &userVal4)
{
    userVal1 ^= userVal2 ^= userVal1 ^= userVal2;
    userVal3 ^= userVal4 ^= userVal3 ^= userVal4;
}

int main()
{
    int userVal1, userVal2, userVal3, userVal4;
    cin >> userVal1;
    cin >> userVal2;
    cin >> userVal3;
    cin >> userVal4;

    SwapValues(userVal1, userVal2, userVal3, userVal4);

    cout << userVal1 << " " << userVal2 << " " << userVal3 << " " << userVal4 << endl;

    return 0;
}
