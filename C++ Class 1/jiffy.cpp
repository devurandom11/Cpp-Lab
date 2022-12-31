#include <iostream>
#include <iomanip>

double JiffiesToSeconds(double userJiffies)
{
    return userJiffies / 100.0;
}

int main()
{
    double jiffies;
    std::cin >> jiffies;

    // Output the result with three digits after the decimal point
    std::cout << std::fixed << std::setprecision(3) << JiffiesToSeconds(jiffies) << '\n';

    return 0;
}
