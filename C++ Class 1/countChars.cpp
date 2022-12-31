#include <iostream>
#include <string>

int main()
{
    char inputChar;
    std::cin >> inputChar;

    std::string inputString;
    std::getline(std::cin, inputString);

    int charCount = 0;
    for (const char c : inputString)
    {
        if (c == inputChar)
        {
            ++charCount;
        }
    }

    std::cout << charCount << " " << inputChar << (charCount == 1 ? "" : "'s") << '\n';

    return 0;
}
