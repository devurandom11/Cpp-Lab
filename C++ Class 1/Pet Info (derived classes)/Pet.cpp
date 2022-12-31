#include "Pet.h"
#include <iostream>
#include <string>
using namespace std;

void Pet::SetName(string userName)
{
    petName = userName;
}

string Pet::GetName()
{
    return petName;
}

void Pet::SetAge(int userAge)
{
    petAge = userAge;
}

int Pet::GetAge()
{
    return petAge;
}

void Pet::PrintInfo()
{
    cout << "Pet Information: " << endl;
    cout << "   Name: " << petName << endl;
    cout << "   Age: " << petAge << endl;
}