#include <iostream>
using namespace std;

int main()
{
    int orderedBerries;

    cin >> orderedBerries;

    if ((orderedBerries >= 20) && (orderedBerries <= 60))
    {
        cout << "Large bin" << endl;
    }
    else if ((orderedBerries >= 100) && (orderedBerries <= 110))
    {
        cout << "Extra large bin" << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int suppliedForks;

    cin >> suppliedForks;

    if ((suppliedForks > 25) && (suppliedForks <= 47))
    {
        cout << "Basic carton" << endl;
    }
    else if ((suppliedForks > 106) && (suppliedForks <= 151))
    {
        cout << "Standard carton" << endl;
    }
    else
    {
        cout << "Select another amount" << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int carYear;

    cin >> carYear;

    if (carYear < 1967)
    {
        cout << "Probably has few safety features." << endl;
    }
    if (carYear > 1969)
    {
        cout << "Probably has seat belts." << endl;
    }
    if (carYear > 1991)
    {
        cout << "Probably has electronic stability control." << endl;
    }
    if (carYear > 2001)
    {
        cout << "Probably has airbags." << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int userNum1;
    int userNum2;

    cin >> userNum1;
    cin >> userNum2;

    if (userNum1 < 0)
    {
        cout << "userNum1 is negative." << endl;
    }
    if (userNum2 > 12)
    {
        userNum2 = 1;
    }
    else if (userNum2 <= 12)
    {
        cout << "userNum2 is less than or equal to 12." << endl;
    }

    cout << "userNum2 is " << userNum2 << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int nextChoice;

    cin >> nextChoice;

    switch (nextChoice)
    {
    case 0:
        cout << "Rock" << endl;
        break;

    case 1:
        cout << "Paper" << endl;
        break;

    case 2:
        cout << "Scissors" << endl;
        break;

    default:
        cout << "Unknown" << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    char origLetter;

    cin >> origLetter;

    switch (origLetter)
    {
    case 'a':
    case 'A':
        cout << "Alpha" << endl;
        break;

    case 'b':
    case 'B':
        cout << "Beta" << endl;
        break;

    default:
        cout << "Unknown" << endl;
    }

    return 0;
}