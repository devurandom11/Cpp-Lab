#include "Flower.h"
#include <iostream>

void Flower::SetPlantType(bool userIsAnnual)
{
    isAnnual = userIsAnnual;
}

bool Flower::GetPlantType() const
{
    return isAnnual;
}

void Flower::SetColorOfFlowers(string userColorOfFlowers)
{
    colorOfFlowers = userColorOfFlowers;
}

string Flower::GetColorOfFlowers() const
{
    return colorOfFlowers;
}

void Flower::PrintInfo() const
{
    cout << "Plant Information:" << endl;
    cout << "   Plant name: " << plantName << endl;
    cout << "   Cost: " << plantCost << endl;
    cout << "   Annual: " << boolalpha << isAnnual << endl;
    cout << "   Color of flowers: " << colorOfFlowers << endl;
}