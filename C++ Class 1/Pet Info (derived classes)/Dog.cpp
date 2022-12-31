#include "Dog.h"
#include <iostream>
#include <string>
using namespace std;

void Dog::SetBreed(string userBreed)
{
    dogBreed = userBreed;
}

string Dog::GetBreed()
{
    return dogBreed;
}