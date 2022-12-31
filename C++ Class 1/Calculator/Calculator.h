#ifndef CALCULATORH
#define CALCULATORH

class Calculator
{
public:
    // TODO: Declare default constructor
    Calculator();
    // TODO: Declare member functions -
    //       Add(), Subtract(), Multiply(), Divide(), Clear(), GetValue()
    void Add(double);
    void Subtract(double);
    void Multiply(double);
    void Divide(double);
    void Clear();
    double GetValue();

private:
    // TODO: Declare private data member - value
    double value;
};

#endif