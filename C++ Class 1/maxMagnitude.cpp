// Write a function MaxMagnitude() with three integer parameters that returns the largest magnitude value. Use the function in the main program that takes three integer inputs and outputs the largest magnitude value.

// Ex: If the inputs are:

// 5 7 9

// function MaxMagnitude() returns and the main program outputs:

// 9

// Ex: If the inputs are:

// -17 -8 -2

// function MaxMagnitude() returns and the main program outputs:

// -17

// Note: The function does not just return the largest value, which for -17 -8 -2 would be -2. Though not necessary, you may use the absolute-value built-in math function.

// Your program must define and call a function:
// int MaxMagnitude(int userVal1, int userVal2, int userVal3)

#include <iostream>
#include <cstdlib>

using namespace std;

int MaxMagnitude(int userVal1, int userVal2, int userVal3)
{
    int max;

    max = userVal1;
    if (abs(userVal2) > abs(max))
    {
        max = userVal2;
    }
    if (abs(userVal3) > abs(max))
    {
        max = userVal3;
    }

    return max;
}

int main()
{
    int userVal1, userVal2, userVal3, max;
    cin >> userVal1;
    cin >> userVal2;
    cin >> userVal3;

    max = MaxMagnitude(userVal1, userVal2, userVal3);

    cout << max << endl;

    return 0;
}