#ifndef LABPRINTER_H
#define LABPRINTER_H
#include <iostream>
#include <string>

class LabPrinter
{
protected:
    const std::string secret;

public:
    LabPrinter(std::string secretStringValue) : secret(secretStringValue)
    {
    }

    virtual void Print2Plus2()
    {
        using namespace std;
        cout << "2 + 2 = 4" << endl;
    }

    virtual void PrintSecret()
    {
        using namespace std;
        cout << "Secret string: \"" << secret << "\"" << endl;
    }
};

#endif