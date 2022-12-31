#include <iostream>

int main()
{
    int userInput;
    std::cin >> userInput;

    if (userInput < 11 || userInput > 100)
    {
        std::cout << "Input must be 11-100" << '\n';
    }
    else
    {
        for (int i = userInput; i > 10; --i)
        {
            if (i % 11 == 0)
            {
                std::cout << i << '\n';
                break;
            }
            else
            {
                std::cout << i << ' ';
            }
        }
    }

    return 0;
}
