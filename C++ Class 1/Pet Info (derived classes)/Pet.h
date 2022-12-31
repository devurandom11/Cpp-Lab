#ifndef PETH
#define PETH

#include <string>
using namespace std;

class Pet
{
protected:
    string petName;
    int petAge;

public:
    void SetName(string userName);

    string GetName();

    void SetAge(int userAge);

    int GetAge();

    void PrintInfo();
};

#endif
