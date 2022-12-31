#include <iostream>
#include <vector>
#include <stdexcept>

int main()
{
    // set vector
    std::vector<std::string> names = {"Ryley", "Edan", "Reagan", "Henry", "Caius", "Jane", "Guto", "Sonya", "Tyrese", "Johnny"};

    // get index
    int index;
    std::cin >> index;

    // inside try
    try
    {
        std::cout << names.at(index) << '\n';
    }
    catch (const std::out_of_range &oor)
    {
        std::cout << "Exception! " << oor.what() << '\n';

        // Get the size of the vector
        const int indexLength = names.size();

        // Print the closest name
        if (index >= indexLength)
        {
            std::cout << "The closest name is: " << names.at(indexLength - 1) << '\n';
        }
        else
        {
            std::cout << "The closest name is: " << names.at(0) << '\n';
        }
    }

    return 0;
}
