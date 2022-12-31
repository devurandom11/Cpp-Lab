#include <iostream>
#include "Calculator.h"
using namespace std;

// TODO: Define default constructor
Calculator::Calculator()
{
    this->value = 0;
}
// TODO: Define member functions -
//       Add(), Subtract(), Multiply(), Divide(), Clear(), GetValue()
void Calculator::Add(double num)
{
    this->value += num;
}

void Calculator::Subtract(double num)
{
    this->value -= num;
}

void Calculator::Multiply(double num)
{
    this->value *= num;
}

void Calculator::Divide(double num)
{
    this->value /= num;
}

void Calculator::Clear()
{
    this->value = 0;
}

double Calculator::GetValue()
{
    return this->value;
}