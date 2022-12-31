#ifndef STATEPAIR
#define STATEPAIR

#include <iostream>
using namespace std;

template <typename T1, typename T2>
class StatePair
{

private:
    T1 key;
    T2 value;

public:
    StatePair()
    {
    }

    // Add parameterized constructor that initialize key and value to specified values
    StatePair(T1 key, T2 value)
    {
        this->key = key;
        this->value = value;
    }

    void SetKey(T1 key)
    {
        this->key = key;
    }

    void SetValue(T2 value)
    {
        this->value = value;
    }

    T1 GetKey() { return key; }

    T2 GetValue() { return value; }

    void PrintInfo()
    {
        cout << key << ": " << value << endl;
    }
};

#endif