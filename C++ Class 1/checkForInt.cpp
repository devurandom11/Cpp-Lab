#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string userString;
    std::cin >> userString;

    bool allDigits = true;
    for (const char c : userString)
    {
        if (!std::isdigit(c))
        {
            allDigits = false;
            break;
        }
    }

    std::cout << (allDigits ? "Yes" : "No") << '\n';

    return 0;
}
