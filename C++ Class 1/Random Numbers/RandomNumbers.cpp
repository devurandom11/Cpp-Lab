#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RandomNumbers.h"
using namespace std;

/* Type your code here */

// Setter
void RandomNumbers::SetRandomValues(int low, int high)
{
    srand(time(0));
    this->var1 = low + (rand() % (high - low + 1));
    this->var2 = low + (rand() % (high - low + 1));
    this->var3 = low + (rand() % (high - low + 1));
}

// Getters
void RandomNumbers::GetRandomValues()
{
    cout << "Random values: " << this->var1 << " " << this->var2 << " " << this->var3 << endl;
}

int RandomNumbers::GetVar1()
{
    return this->var1;
}

int RandomNumbers::GetVar2()
{
    return this->var2;
}

int RandomNumbers::GetVar3()
{
    return this->var3;
}