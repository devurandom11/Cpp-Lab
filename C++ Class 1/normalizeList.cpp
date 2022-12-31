// When analyzing data sets, such as data for human heights or for human weights, a common step is to adjust the data. This adjustment can be done by normalizing to values between 0 and 1, or throwing away outliers.

// For this program, adjust the values by dividing all values by the largest value. The input begins with an integer indicating the number of floating-point values that follow.

// Output each floating-point value with two digits after the decimal point, which can be achieved by executing
// cout << fixed << setprecision(2); once before all other cout statements.

// Ex: If the input is:

// 5 30.0 50.0 10.0 100.0 65.0

// the output is:

// 0.30 0.50 0.10 1.00 0.65

// The 5 indicates that there are five floating-point values in the list, namely 30.0, 50.0, 10.0, 100.0, and 65.0. 100.0 is the largest value in the list, so each value is divided by 100.0.

// For coding simplicity, follow every output value by a space, including the last one.
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int numFloats;
    int i;
    float largest;

    // Get the number of floating point numbers.
    cin >> numFloats;

    // Get floating point numbers
    vector<float> floatNums(numFloats);
    for (i = 0; i < numFloats; i++)
    {
        cin >> floatNums.at(i);
    }

    // Find largest floating point number.
    largest = floatNums.at(0);
    for (i = 0; i < numFloats; i++)
    {
        if (largest <= floatNums.at(i))
        {
            largest = floatNums.at(i);
        }
    }

    // Normalize list
    for (i = 0; i < numFloats; i++)
    {
        floatNums.at(i) /= largest;
    }

    // Print results
    cout << fixed << setprecision(2);
    for (i = 0; i < numFloats; i++)
    {
        cout << floatNums.at(i) << " ";
    }
    cout << endl;
    return 0;
}
