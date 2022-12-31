#ifndef DOGH
#define DOGH

#include <string>
#include "Pet.h"

class Dog : public Pet
{
private:
    string dogBreed;

public:
    void SetBreed(string userBreed);

    string GetBreed();
};

#endif