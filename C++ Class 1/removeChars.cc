#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userInput;
    getline(cin, userInput);

    for (unsigned i = 0; i < userInput.length(); i++)
    {
        if (!isalpha(userInput.at(i)))
        {
            userInput.erase(i, 1);
            i--;
        }
    }
    cout << userInput << endl;
    return 0;
}
