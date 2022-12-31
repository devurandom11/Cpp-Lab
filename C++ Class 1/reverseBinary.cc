#include <iostream>
using namespace std;

int main()
{

    int userInput;

    cin >> userInput;

    if (userInput > 0)
    {
        while (userInput > 0)
        {
            cout << userInput % 2;
            userInput /= 2;
        }
        cout << endl;
    }

    return 0;
}
