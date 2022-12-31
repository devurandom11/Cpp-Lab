#include <iostream>
#include <vector> // Must include vector library to use vectors
using namespace std;

// Write a program that reads a list of integers, and outputs those integers in reverse. The input begins with an integer indicating the number of integers that follow. For coding simplicity, follow each output integer by a comma, including the last one.

int main()
{
    vector<int> userInts; // A vector to hold the user's input integers
    int totInts;
    unsigned i;
    int j;

    cin >> totInts;

    userInts.resize(totInts);
    for (i = 0; i < userInts.size(); i++)
    {
        cin >> userInts.at(i);
    }
    for (j = userInts.size() - 1; j >= 0; j--)
    {
        cout << userInts.at(j) << ",";
    }

    cout << endl;
    return 0;
}
