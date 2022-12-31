// Output each floating-point value with two digits after the decimal point, which can be achieved by executing
// cout << fixed << setprecision(2); once before all other cout statements.

// (1) Prompt the user to enter five numbers, being five people's weights. Store the numbers in a vector of doubles. Output the vector's numbers on one line, each number followed by one space. (2 pts)

// Ex:

// Enter weight 1:
// 236.0
// Enter weight 2:
// 89.5
// Enter weight 3:
// 142.0
// Enter weight 4:
// 166.3
// Enter weight 5:
// 93.0
// You entered: 236.00 89.50 142.00 166.30 93.00

// (2) Also output the total weight, by summing the vector's elements. (1 pt)

// (3) Also output the average of the vector's elements. (1 pt)

// (4) Also output the max vector element. (2 pts)

// Ex:

// Enter weight 1:
// 236.0
// Enter weight 2:
// 89.5
// Enter weight 3:
// 142.0
// Enter weight 4:
// 166.3
// Enter weight 5:
// 93.0
// You entered: 236.00 89.50 142.00 166.30 93.00

// Total weight: 726.80
// Average weight: 145.36
// Max weight: 236.00

#include <iostream>
#include <iomanip> // For setprecision
#include <vector>
using namespace std;

void printVector(vector<double> userVec)
{
    cout << fixed << setprecision(2);
    cout << "You entered: ";
    for (unsigned i = 0; i < userVec.size(); ++i)
    {
        cout << userVec[i] << " ";
    }
    cout << endl;
}

double add(vector<double> userVec)
{
    double sum = 0.0;
    for (unsigned i = 0; i < userVec.size(); ++i)
    {
        sum += userVec[i];
    }
    return sum;
}

double avg(double sum)
{
    double avg = sum / 5.0;
    return avg;
}

double max(vector<double> userVec)
{
    double max = userVec.at(0);
    for (unsigned i = 0; i < userVec.size(); ++i)
    {
        if (userVec[i] > max)
        {
            max = userVec[i];
        }
    }
    return max;
}

int main()
{
    vector<double> userVec(5);

    for (auto i = 0; i < 5; ++i)
    {
        cout << "Enter weight " << i + 1 << ":" << endl;
        cin >> userVec[i];
    }
    printVector(userVec);
    cout << fixed << setprecision(2);
    cout << endl;
    cout << "Total weight: " << add(userVec) << endl;
    cout << "Average weight: " << avg(add(userVec)) << endl;
    cout << "Max weight: " << max(userVec) << endl;

    return 0;
}