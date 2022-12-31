#include <iostream>
#include <vector>
#include <string>

int main()
{
    int numWords;
    std::cin >> numWords;

    std::vector<std::string> words(numWords);
    for (int i = 0; i < numWords; ++i)
    {
        std::cin >> words[i];
    }

    char targetChar;
    std::cin >> targetChar;

    for (const std::string &word : words)
    {
        if (word.find(targetChar) != std::string::npos)
        {
            std::cout << word << ',';
        }
    }
    std::cout << '\n';

    return 0;
}
